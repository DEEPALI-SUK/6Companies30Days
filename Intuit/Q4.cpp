#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void func(string &s,string &mx,int k,int n,int p){
        if(s>mx){
            mx=s;
        }
        if(k==0)return ;
        if(p==n)return;
        char m=s[p];
        for(int i=p+1;i<n;i++){
            m=max(m,s[i]);
        }
        if(s[p]!=m)k--;
        for(int j=n-1;j>=p;j--){
            if(s[j]==m){
                swap(s[j],s[p]);
                func(s,mx,k,n,p+1);
                swap(s[j],s[p]);
            }
        }
        /*for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[j]>s[i]){
                    swap(s[j],s[i]);
                    func(s,mx,k-1,n);
                    swap(s[j],s[i]);
                }
            }
        }*/
    }
    string findMaximumNum(string s, int k)
    {
       // code here.
       int n=s.length();
       string mx=s;
       func(s,mx,k,n,0);
       return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends