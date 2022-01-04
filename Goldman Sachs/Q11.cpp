#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        long long int sum = 0;
        long long int sum2 = 0;
        for(int i=0;i<n;i++) {
            sum = sum + arr[i];
            sum2 = sum2 + (long long int)arr[i]*arr[i];
        }
        long long int sum3 = ((long long int)n*(n+1))/2;
        long long int sum4 = ((long long int)n*(n+1)*(2*n+1))/6;
        long long int m1 = sum - sum3;
        long long int m2 = sum2 - sum4;
        m2 = m2/m1;
        int mis = (m1 + m2)/2;
        int rep = mis - m1;
        int *ans = new int[2];
        ans[1] = rep;
        ans[0] = mis;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends