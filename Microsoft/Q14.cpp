// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int d){
        // code here
        int sum=0,ans=0;
        if(d==0)return 0;
        while(sum<d){
            sum+=ans;
            ans++;
        }
        while((sum-d)%2){
            sum+=ans;
            ans++;
        }
        return ans-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends