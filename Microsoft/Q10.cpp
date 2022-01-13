using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	   int dp[n]={0};
	    
	    for(int i=0;i<n;i++){
	       if(i>=2) dp[i]=max(dp[i-1],a[i]+dp[i-2]);
	       else if(i>=1) dp[i]=max(dp[i-1],a[i]);
	       else dp[i]=a[i];
	    }
	   cout<<dp[n-1]<<endl; 
	}
	return 0;
}