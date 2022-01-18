#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int CeilIndex(vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
     int LIS(vector<int>& v)
{
    if (v.size() == 0)
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1; 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
 
    return length;
}
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        map <int,int> m;
       
       for(int i=0;i<M;i++)
       {
           m.insert({B[i],i});
       }
       
       vector <int> v;
       int cny=0;
       for(int i=0;i<N;i++)
       {
            if (m.find(A[i]) == m.end())
        {
            cny++;
        }
        else
        {
            v.push_back(A[i]);
        }
       }
       int l =  LIS(v) ;
       int res = (v.size() - l + cny)  + (M-l);
       return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends