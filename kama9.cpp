#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    //输入数据有多组
    while(cin>>x){
        int n=0,res = 0;
        //如何才能停止整除这个动作
        while(x>0){
            n = x % 10;
            if(n % 2 == 0){
                res = res + n;
            }
            x = x / 10;
            //cout<<x<<endl;
        }
        cout<<res<<endl<<endl;
    }

    return 0;
}


#include <iostream>

using namespace std;

int main(){
    string s;

    while(getline(cin,s))
    while(getline(cin , s)){
        // 逐行读取
        int sum = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int num = s[i] - '0';
            if(num % 2 == 0)
                sum += num;
        }
        cout << sum << endl;
        cout << endl;
    }
    
    return 0;
}