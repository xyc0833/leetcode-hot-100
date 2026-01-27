#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,k;
    while(cin>>m>>k){
        if(m == 0 && k == 0){
            break;
        }
        //我的想法是 用 do while
        int b = 0,s = 0; //b是整除之后的 s是余数
        do{
            b = m/k; s = m % k
             
        }while() //这个值应该是大于 k?

    }

    return 0;
}


//看一下正确答案


#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,k;
    while(cin>>m>>k){
        if(m == 0 && k == 0){
            break;
        }
        //先获取第一轮的 总话费
        int sum = m + m/k;
        //获取第一轮的额外话费 = 赠送 + 剩余话费
        int count = m/k + m % k;
        //只要额外话费大于k就还能获得 剩余话费
        while(count / k !=0){
            sum = sum + count / k;
            count = count/k + count % k;
        }
        cout<<sum<<endl;
    }

    return 0;
}