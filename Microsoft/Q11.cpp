#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n

vector<string> generate(long long n)
{
	// Your code here
	vector<string> ans;

queue<string> q;

q.push("1");

while(n--)

{

string curr=q.front();

ans.push_back(curr);

q.pop();

q.push(curr+"0");

q.push(curr+"1");

}

return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends