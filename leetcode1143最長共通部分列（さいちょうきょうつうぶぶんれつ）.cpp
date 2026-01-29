class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 1. dp配列とインデックスの意味を決定する
        // dp[i][j]は、text1の0からi-1までとtext2の0からj-1までの最長共通部分列を表す
        // 初期化について
        // dp[i][0]は何になるか？
        // text1[0, i-1]と空文字列の最長共通部分列は0なので、dp[i][0] = 0;
        int n = text1.size(); int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // 2. 探索順序を決定する（上から下、左から右）
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
};
