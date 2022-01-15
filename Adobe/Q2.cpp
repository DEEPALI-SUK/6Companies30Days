class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i];
                if(dp[i].find(d)!=dp[i].end()){
                    dp[j][d]=dp[i][d]+1;
                }else dp[j][d]=2;
                mx=max(mx,dp[j][d]);
            }
        }
        return mx;
    }
};