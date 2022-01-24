class Solution {
public:
   
vector<char> color;
         vector<int> parent;
        int cycle_start, cycle_end;
bool dfs(int v,vector<int> adj[]) {
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u,adj))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int find_cycle(vector<int> adj[],int n) {
    
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v,adj))
            break;
    }

    if (cycle_start == -1) {
        return 0;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        return 1;
        
    }
}
    void ts(int v,vector<int>&vis,stack<int>&st,vector<int> adj[]){
        vis[v]=1;
        for(auto i:adj[v]){
            if(vis[i]==0) ts(i,vis,st,adj);
        }
        st.push(v);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
         vector<int> ans;
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> vis(n,0);
         if(find_cycle(adj,n))return ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ts(i,vis,st,adj);
            }
        }
       
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};