#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n&1)return false;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]%k]++;
        }
        for(auto i:mp){
            if(i.first==0){
                if(i.second&1)return false;
            }else if(i.first==(k/2) && k%2==0){
                if(i.second&1)return false;
            }else if(i.second!=mp[k-i.first])return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends