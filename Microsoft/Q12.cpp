class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        vector<vector<int> > ans;
        map<vector<int>,int> mp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1,s=k-nums[i]-nums[j];
                while(l<r){
                    if(nums[l]+nums[r]==s){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        if(mp.find(v)==mp.end()){
                            ans.push_back(v);
                            mp[v]++;
                        }
                        l++;
                        r--;
                    }else if(nums[l]+nums[r]>s)r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};