#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    // Code here
		    int n=s.length();
            if (n == 0 || (n == 1 && s[0] == '0'))return 0;
            int c[n+1];
            c[0] = 1;
            c[1] = 1;

            if(s[0]=='0') return 0;
            for (int i = 2; i <= n; i++)
            {
                c[i] = 0;
                if (s[i-1] > '0')c[i] = c[i-1];

                if (s[i-2] == '1' ||(s[i-2] == '2' && s[i-1] < '7') )
                    c[i] = (c[i]+c[i-2])%(1000000007);
            }
            return c[n]%(1000000007);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends