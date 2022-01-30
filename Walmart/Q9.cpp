class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int e = j+i;
                for(int k=j; k<e; k++){
                    int x = k+1;
                    if(j==k){
                        dp[j][e] = x+ dp[j+1][e];
                    }else{
                        dp[j][e] = min(dp[j][e], max(dp[j][k], dp[k+1][e]) + x);
                    }
                }
            }
        }
        return dp[0][n];
    }
};