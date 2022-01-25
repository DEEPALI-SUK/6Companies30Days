class Solution {
public:
    bool func(int mid , vector<int>& nums , int m){
        int sub_array=0;
        for (int pile : nums) {
                sub_array += pile / mid + (pile % mid != 0);
            }
        return (sub_array<=m);
    }
    int minEatingSpeed(vector<int>& nums, int m) {
        int l=1;
        int r=0;
        for(int i=0;i<nums.size();i++)r=max(r,nums[i]);
        while(l<r){
            int mid=(l+r)/2;
            if(func(mid,nums,m))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};