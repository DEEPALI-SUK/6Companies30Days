class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n=nums.size();
        int l=0,sum=0,m=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=t){
                sum-=nums[l];
                m=min(m,i-l+1);
                l++;
            }
        }
        if(m==INT_MAX)m=0;
        return m;
    }
};