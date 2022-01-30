class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ej, vector<double>& p, int s, int e) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<ej.size(); i++) {
            g[ej[i][0]].push_back({ej[i][1], p[i]});
            g[ej[i][1]].push_back({ej[i][0], p[i]});   
        }
        vector<int> vis(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({1, s});
        vector<double> res(n,0);
        res[s] = 1.0;
        while(!q.empty()) {
            pair<double, int> p = q.top();
            q.pop();
            double w = p.first;
            int u = p.second;
            if(vis[u]==0) {
                vis[u]++;
                for(auto y: g[u]) {
                    if (res[y.first] < y.second*w) {
                        res[y.first] = y.second*w;
						q.push({res[y.first], y.first});
                    }
                }
            }
        }
        return res[e];
    }
};