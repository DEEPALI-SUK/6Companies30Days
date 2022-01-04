#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string r){
        // code here 
        string ans="";
        stack<int> s;
        int num=1;
        for(int i=0;i<r.length();i++){
            if(r[i]=='D'){
               s.push(num);
               num++;
            }else{
                s.push(num);
                while(!s.empty()){
                    char c= s.top()+'0';
                    ans+=c;
                    s.pop();
                }
                num++;
            }
        }
        s.push(num);
                while(!s.empty()){
                    char c= s.top()+'0';
                    ans+=c;
                    s.pop();
                }
                return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends