#include<bits/stdc++.h>
using namespace std;
//参考leetcode1143
int longestCommonSubsequence(string text1, string text2) {
    //1 确定dp数组 以及下标的含义
    //dp[i][j]表示长度从0到i-1和0到j-1的最长公共子序列为 dp[i][j]
    // 如果初始化
    //先看看dp[i][0]应该是多少呢？
    //text1[0, i-1]和空串的最长公共子序列自然是0，所以dp[i][0] = 0;
    int n = text1.size(); int m = text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //确定遍历顺序 从上到下 从左到右
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        cout<<longestCommonSubsequence(s1,s2)<<endl;
    }
    return 0;
}