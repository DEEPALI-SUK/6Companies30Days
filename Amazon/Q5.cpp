// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string c[], string s)
    {
        // code here
        set<string> st;
        
        map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            if(st.count(c[i])==0){
            int m=c[i].length();
            for(int j=0;j<m;j++){
                mp[c[i].substr(0,j+1)].push_back(c[i]);
            }
            st.insert(c[i]);
            }
        }
        for(auto i:mp){
           sort(i.second.begin(),i.second.end());
            mp[i.first]=i.second;
        }
        vector<vector<string>>ans;
        for(int i=0;i<s.length();i++){
            string g=s.substr(0,i+1);
            if(mp.find(g)!=mp.end())ans.push_back(mp[g]);
            else {
                vector<string> v;
                v.push_back("0");
                ans.push_back(v);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends