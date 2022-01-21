//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string s) { 
        //complete the function here
        int n=s.length();
        if(n==1 || n==2 || n==3)return "-1";
        int m=n/2;
        string s1=s.substr(0,m);
        //cout<<s1<<endl;
        next_permutation(s1.begin(),s1.end());
        if(s1<=s.substr(0,m))return "-1";
        string g=s1;
        reverse(g.begin(),g.end());
        if(n&1)s1+=s[n/2];
        
        s1+=g;
        return s1;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends