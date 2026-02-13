//华南溜达虎
class node{
public:
    node* next;
    node* pre;
    int key;int value;
    //构造函数
    node(int k,int v){
        key = k;
        value = v;
        next = NULL;
        pre = NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        //构造函数的实现
        //初始化容量
        cap = capacity;
        head = new node(0,0);
        tail = new node(0,0);
        //一开始双向链表为空 head要指向tail tail也要指向head
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        //需要去hash表中看一下给定的key是否存在
        //如果存在需要返回对应的value

        //在返回之前需要把 key value组成的node移动到双向链表的最左端
        if(u_map.count(key) == true){
            //首先需要把双向链表中的key对应的节点删掉
            remove(u_map[key]);
            //然后插入到链表的最左端
            headinsert(u_map[key]);//在这里 相当于最左侧是最近使用的位置
            return u_map[key]->value;
        }
        //如果key不在hash表中 直接返回-1
        return -1;
    }
    
    void put(int key, int value) {
        //如果key已经在hash表中
        //只需要更新对应的value

        //更新之前只需要将旧的节点从双向链表中删掉
        if(u_map.count(key) == true){
            remove(u_map[key]);
            delete u_map[key];
            u_map[key] = NULL;
        }
        //接着创建一个新的node 
        node* tmp = new node(key,value);
        //把新node放到双向链表的最左端
        headinsert(tmp);
        //同时把它插入到hash表中
        u_map[key] = tmp;
        //插入完成 需要判断当前数据结构的大小是否超过了给定的容量
        if(u_map.size()>cap){
            //如果超过了 需要把双向链表最右边的节点删掉
            node* todel = tail->pre;//尾部节点的前面一个节点是真正的最后一个节点
            remove(todel);
            u_map.erase(todel->key);
            delete todel;
        }
    }
    void remove(node* tmp){
        //删除的话 保存tmp的前面和 后面
        node* tmp_pre = tmp->pre;
        node* tmp_next = tmp->next;
        //让前面的指向后面（跳过tmp本身）
        tmp_pre->next = tmp_next;
        //让后面的指向前面 就算完成删除了
        tmp_next->pre = tmp_pre;
    }
    //头部插入
    void headinsert(node* tmp){
        //先保存一下 头部的下一个节点
        node* nxt = head->next;
        //然后头部的next指针指向temp
        head->next = tmp;
        tmp->pre = head;
        //tmp指向nxt
        tmp->next = nxt;
        nxt->pre = tmp;
    }

private:
    int cap;
    node* head,*tail;
    unordered_map<int ,node*> u_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */