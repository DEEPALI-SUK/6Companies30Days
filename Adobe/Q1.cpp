#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long s)
    {
        // Your code here
        long long s1=0;
        int i=0,l=0;
        while(i<n){
            s1+=a[i];
            while(s1>s && l<=i){s1-=a[l];l++;}
            if(s1==s){
                vector<int> v;
                v.push_back(l+1);
                v.push_back(i+1);
                return v;
            }
            i++;
        }
        if(s1==s){
                vector<int> v;
                v.push_back(l+1);
                v.push_back(n);
                return v;
            }else {
                vector<int> v;
                v.push_back(-1);
                return v;
            }
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends