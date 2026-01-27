//思路 自己先举例子模拟一下
//先求和算平均值
//大于平均值的部分 累加 返回答案

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  //有多组输入
  while (cin >> n) {
    if(n == 0) break;
    
    int sum = 0;
    vector<int> k(n,0);

    //读取n个堆的高度并计算总和
    for(int i=0;i<n;i++){
        cin>>k[i];
        sum = sum + k[i];
    }

    int avg = sum / k.size();
    int result = 0;

    for (int i = 0; i < k.size(); i++) {
      if (k[i] > avg) {
        result = result + (k[i] - avg);
      }
    }
    cout << result << endl<<endl;
  }

  return 0;
}