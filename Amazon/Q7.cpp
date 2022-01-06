#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    queue<char> q;
		    string ans="";
		    unordered_map<char,int> mp;
		    for(int i=0;i<a.length();i++){
		        mp[a[i]]++;
		        if(q.empty() && mp[a[i]]<=1){
		          q.push(a[i]);  
		          ans+=q.front();
		        }else {
		            
		            
		                while(!q.empty() && mp[q.front()]>1)q.pop();
		                if(q.empty())ans+="#";
		                else{ ans+=q.front();q.push(a[i]);}
		            
		        }
		        
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends