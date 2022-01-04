// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // code here
        int x1,x2,x3,x4,y1,y2,y3,y4;
        x1=l1[0];
        x2=r1[0];
        y1=l1[1];
        y2=r1[1];
        x3=l2[0];
        x4=r2[0];
        y3=l2[1];
        y4=r2[1];
        
        if(x3>x2||x1>x4||y1<y4||y3<y2)return 0;
        return 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends