class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int c = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < n; j++) {
                int d = pow(p[j][1] - p[i][1], 2) + pow(p[j][0] - p[i][0], 2);
                if (mp[d] > 0) {
                    c += mp[d] << 1;
                }
                mp[d]++;
            }
        }
        return c;
    }
};