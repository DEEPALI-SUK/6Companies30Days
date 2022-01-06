// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        k=min(k,n/2);
        int p[k+1][n+1];
        for (int i = 0; i <= k; i++)p[i][0] = 0;
        for (int j = 0; j <= n; j++)p[0][j] = 0;
        for (int i = 1; i <= k; i++) {
            int prevdiff = INT_MIN;
            for (int j = 1; j < n; j++) {
                prevdiff = max(prevdiff,p[i-1][j-1]-a[j-1]);
                p[i][j] = max(p[i][j-1],a[j]+prevdiff);
            }
        }
 
        return p[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends