class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        int mod = 1e9+7;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        multiset<int> st;
        long long ans = 0,sum=0;
        for(int i=0;i<n;i++)
        {
            st.insert(v[i].second);
            sum+= v[i].second;
            ans = max(ans,sum*v[i].first);
            if(st.size() == k)
            {
                sum -= *st.begin();
                st.erase(st.begin());
            }
        }
        return (ans%mod);
    }
};