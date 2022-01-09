#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int s[28][28];

    void print(int i,int j,string &ans)
    {
        if(i==j)
        {
        ans+=char(i+'A'-1);
        return;
        }
        ans+="(";
        print(i,s[i][j],ans);
        print(s[i][j]+1,j,ans);
        ans+=")";
    }
    string matrixChainOrder(int p[], int n){
        // code here
        string ans="";
        int dp[28][28];
	    memset(dp,0,sizeof(dp[0][0])*28*28);
	    int sum,j;
	    for(int len=2;len<n;len++)
	    {
	        for(int i=1;i<n-len+1;i++)
	        {
	            int mn=INT_MAX-1;
	            j=i+len-1;
	            for(int k=i;k<j;k++)
	            {
	                sum=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
	                if(mn>sum)
	                {
	                    mn=sum;
	                    s[i][j]=k;
	                }
	            }
	            dp[i][j]=mn;
	        }
	        
	    }
	    print(1,n-1,ans);
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
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends