#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    sort(a,a+n);
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=a[i];
	    int dp[(sum/2)+1]={0};
	    dp[0]=1;
	    for(int i=0;i<n;i++){
	        for(int j=(sum/2);j>=a[i];j--){
	            if(dp[j-a[i]]==1)dp[j]=1;
	        }
	    }
	    for(int j=(sum/2);j>=0;j--){
	            if(dp[j]==1)return (sum-(2*j));
	        }
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends