#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long stn(string s)
{   
    int n=s.length();
    long long x=0;
    for(int i=0;i<n;i++)
      x=x*10+(s[i]-'0');
    return x;
}
int missingNumber(const string& s)
{
    // Code here
    int n=s.length(),mis;
    for(int i=1;i<=6;i++){
       string h=s.substr(0,i);
       int j=i,c=0,fl=0;
       long long num=stn(h);
       h="";
       while(j<n){
           h+=s[j++];
           long long k=stn(h);
           if(num+1==k){
               num=k;
               h="";
           }else if(num+2==k){
             mis=num+1;
             c++;
             num=k;
             h="";
           }else if(num<k){
               fl=1;
           }
           if(fl || c>1)break;
       }
       if(c==1 && fl==0)return mis;
    }
    return -1;
}