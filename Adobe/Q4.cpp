using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
int main() {
	//code
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll a[n],q=0;
	    f(i,0,n){ cin>>a[i];q+=a[i];}
	    ll k=q/2;
	    if(q&1)cout<<"NO\n";
	    //cin>>k;
	    else{
	    ll dp[k+1]={0};
	    dp[0]=1;
	    f(i,1,n){
	        for(ll j=k;j>=a[i];j--){
	            if(dp[j-a[i]]==1 && dp[j]==0) dp[j]=1;
	        }
	    }
	  if(dp[k]==1) cout<<"YES"<<endl; 
	  else cout<<"NO\n";
	    }
	}
	return 0;
}