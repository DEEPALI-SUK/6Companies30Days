#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  string ans="";
  int n=s.length();
  char v=s[0];
  int c=1,i=1;
  while(i<n){
      if(s[i]==v){
          c++;
          i++;
      }else{
          ans+=v;
          ans+=to_string(c);
          v=s[i];
          c=0;
      }
      
  }
  ans+=v;
          ans+=to_string(c);
          return ans;
  
}