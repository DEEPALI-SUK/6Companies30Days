#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        int l=0,n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(i==l){
                ans+=tolower(s[i]);
            }else ans+=s[i];
            if(i+1<n && isupper(s[i+1])){
                ans+=" ";
                l=i+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends