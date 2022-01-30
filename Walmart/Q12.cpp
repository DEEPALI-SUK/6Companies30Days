class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int>v;
        sort(sums.begin(), sums.end());
        for(int i=0; i<n; i++)
        {
            unordered_map<int, int>mp;
            int h=sums[1]-sums[0];
            vector<int>v1, v2;
            int fl=0;
            for(int k=0; k<sums.size(); k++)
            {
                if(!mp[sums[k]])
                {
                    v1.push_back(sums[k]);
                    mp[sums[k]+h]++;
                    if(sums[k]==0)
                        fl=1;
                }
                else
                {
                    v2.push_back(sums[k]);
                    mp[sums[k]]--;
                }
            }
                if(fl) 
                {
                v.push_back(h); 
                sums = v1; 
                }
                else 
                {
                v.push_back(-h); 
                sums = v2; 
                }
            }
        return v; 
    }
};