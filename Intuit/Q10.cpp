class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int n){
        vis[n]=1;
        for(auto i:adj[n]){
            if(vis[i]==0)dfs(adj,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> adj[n],vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c++;
                dfs(adj,vis,i);
            }
        }
        return c;
    }
};