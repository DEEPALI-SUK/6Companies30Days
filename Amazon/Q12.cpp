#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int N)
    {
        // your code here
        string res;
        
        while(N)
        {
            int i = N % 26;
            
            if(i == 0)
            {
                res.push_back('Z');
                N -= 26;
            }
            else
            {
                res.push_back('A' + (i - 1));
                N -= i;
            }
            
            N /= 26;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends