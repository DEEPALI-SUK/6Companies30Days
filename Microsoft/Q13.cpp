#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],vector<int> &vis,int u, int c, int d,int f){
	    vis[u]++;
	    for(auto i:adj[u]){
	        if(vis[i]==0){
	            if(f&&i==c&&u==d)continue;
                if(f&&i==d&&u==c)continue;
	            dfs(adj,vis,i,c,d,f);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        // Code here
        int c1=0;
        int f=0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                c1++;
                dfs(adj,vis,i,c,d,f);
            }
        }
        int c2=0;
        f=1;
        vector<int> vis1(v,0);
        for(int i=0;i<v;i++){
            if(vis1[i]==0){
                c2++;
                dfs(adj,vis1,i,c,d,f);
            }
        }
        if(c1!=c2)return 1;
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends