/**
迭代器相关函数解释（新手必懂）
begin()：集合第一个元素的迭代器；
end()：集合最后一个元素的下一个位置（不是最后一个元素！）；
prev(it)：迭代器向前移动一位（比如 it 指向 1，prev (it) 指向 0）；
next(it)：迭代器向后移动一位（比如 it 指向 1，next (it) 指向 2）；
find(x)：找值为 x 的迭代器，找不到返回end()；
lower_bound(x)：找第一个≥x 的迭代器（这里用x+1就是找 > x 的第一个元素）。
*/


//卡码助手的正确解法
#include<bits/stdc++.h>
//定义换行符 代替cout的endl 更快
#define endl '\n'
//题目中n的最大值为 1e5
const int N = 1e5 + 10;
using namespace std;
//简化坐标对的写法 PII就是（x,y）
using PII = pair<int,int>;

int main(){
    //加速cin/cout:关闭同步 避免慢输入输出
    //处理1e5的数据时 必须加
    cin.tie(nullptr) -> sync_with_stdio(false);

    int n;
    cin>>n;

    //1 分类存储 key是 x/y的坐标 value是有序集合
    //存储对应的y/x坐标
    //x_to_ys[x] = {y1,y2,...} 所有x相同的点的y的坐标
    map<int,set<int>> x_to_ys;
    //y_to_xs[y] = {x1,x2,...} 所有y相同的点的x的坐标
    map<int,set<int>> y_to_xs;
    //存储所有炮的坐标 后续遍历用
    vector<pair<int,int>> all_cannos;

    //2 读取所有炮的坐标 填充分类表 和 坐标数组
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        //把(x,y加入数组)
        all_cannos.push_back({x,y});
        //效率更高的写法
        //all_cannos.emplace_back(x,y);
        //把y加入x对应的有序集合
        x_to_ys[x].insert(y);
        //把x加入y对饮的有序集合
        y_to_xs[y].insert(x);
    }

    //3 遍历每个炮计算能攻击的数量
    //遍历每个炮的坐标
    for(auto[x,y] : all_cannos){
        //能攻击到的总数量
        int attack_count = 0;

        // 第一步 判断左右方向 (同y轴的x坐标集合)
        // 所有和当前炮同y的x坐标
        // 这里的auto 实际上应该是 same_y_xs 是一个 set<int> 类型的有序集合
        const auto&  same_y_xs = y_to_xs[y];
        //左方向判断：找当前x在same_y_xs中的位置
        auto left_it = same_y_xs.find(x); 
        //这里的find是 类似的二分查找 set的底层是红黑树 
        //迭代器的本质是「元素位置标识」，不是具体数值，需用*迭代器获取指向的数值；
        // 条件：不是第一个元素，且前一个元素也不是第一个 → 说明左边有炮架，且炮架后有棋子
        if(left_it != same_y_xs.begin() && prev(left_it) != same_y_xs.begin()){
            attack_count++;
        }
        //右方向判断 找第一个 比x大的坐标（炮架）
        auto right_it = same_y_xs.lower_bound(x+1);
        //类似二分查找>x的第一个x
        //条件： 如果炮架存在 且 炮架不是最后一个元素 炮架后面有棋子可以攻击
        if(right_it != same_y_xs.end() && next(right_it) != same_y_xs.end()){
            attack_count++;
        }

        // 第二步：判断上下方向（同x轴的y坐标集合）
        const auto& same_x_ys = x_to_ys[x];  // 所有和当前炮同x的y坐标（有序）
        // 上方向判断（y更小的方向，因为set从小到大排）
        auto up_it = same_x_ys.find(y);
        if (up_it != same_x_ys.begin() && prev(up_it) != same_x_ys.begin()) {
            attack_count++;
        }
        // 下方向判断（y更大的方向）
        auto down_it = same_x_ys.lower_bound(y + 1);
        if (down_it != same_x_ys.end() && next(down_it) != same_x_ys.end()) {
            attack_count++;
        }

        //输出当前炮的攻击数量
        cout<<attack_count<<endl;
    }

    return 0;
}











// 之前代码 不对的 只能通过样例
#include<bits/stdc++.h>
using namespace std;

//先按照豆包的代码 自己再学习一遍
//四个方向
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

// 安全的坐标哈希函数（替代编码，避免冲突）
struct PairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // 组合哈希值，避免冲突
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //1 用unordered_set存储炮的坐标(无编码冲突 O(1)查询)
    unorder_set<pair<int,int>,PairHash> pos_set;
    //2 保存输入顺序
    vector<pair<int,int>> cannos(n);
    //3 存储每个炮的 可攻击数
    vector<int> ans(n,0);

    //输入炮的坐标
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cannos[i] = {x,y};
        pos_set.insert({x,y});
    }
    //先遍历每个炮
    for(int i=0;i<n;i++){
        int x = cannos[i].first;
        int y = cannos[i].second;
        int count = 0;//可攻击总数

        //遍历四个方向
        for(int i=0;i<4;i++){
            int dx = dir[i][0];
            int dy = dir[i][1];
            int cannos_nums = 0;//统计当前方向遇到的炮数
            int step = 1;//从当前位置的下一个格子开始探索

            while(true){
                //计算当前探索的坐标
                int nx = x + dx * step;
                int ny = y + dy * step;
                //检查当前坐标是否有炮
                if(pos_set.count({nx,ny})){
                    cannos_nums++;
                    if(cannos_nums == 2){
                        count++;
                        break;
                    }
                }
                //终止条件1:找到两个炮了 2 连续走了1000步
                if(cannos_nums >=2 ||step>1000){
                    break;
                }
                step++;
            }
        }
        ans[i] = count;
    }
    // 按输入顺序输出结果
    for(int num : ans){
        cout << num << '\n';
    }

    return 0;
}