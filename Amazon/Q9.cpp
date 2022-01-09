// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> a){
        // code here
        int n=a.size(),m=a[0].size();
        set<string> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=0){
                string g="Row"+to_string(i)+to_string(a[i][j]);
                if(s.count(g)>0)return 0;
                s.insert(g);
                g="Col"+to_string(j)+to_string(a[i][j]);
                if(s.count(g)>0)return 0;
                s.insert(g);
                int k= ((i/3)*3)+(j/3);
                g="Box"+to_string(k)+to_string(a[i][j]);
                if(s.count(g)>0)return 0;
                s.insert(g);
                }
            }
            
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends