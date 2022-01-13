#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    vector<int>degree0(N, 0);
	    
	    for(auto edge : prerequisites)
	    {
	        int u = edge.second;
	        int v = edge.first;
	        adj[u].push_back(v);
	        degree0[v]++;
	    }
	    
	    queue<int>q;
	    for(int i = 0; i < N; i++)
	    {
	        if(degree0[i] == 0)
	            q.push(i);
	    }
	    
	    int c = 0;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        
	        for(auto v: adj[u])
	        {
	            degree0[v]--;
	            if(degree0[v] == 0)
	            {
	                q.push(v);
	            }
	        }
	        c++;
	    }
	    return c==N;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends