 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string s)
    {
        //Your code here
        int i=0,n=s.length(), sum=0,p=1,fl=0;
        if(s[i]=='-'){fl=1;i++;}
        while(i<n){
            if(s[i]-'0' <0 || s[i]-'0'>9)return -1;
            sum= (sum*10)+(s[i]-'0');
            //p=p*10;
            i++;
        }
        if(fl)sum*=-1;
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends