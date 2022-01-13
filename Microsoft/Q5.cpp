#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int price[], int n)
{
   // Your code here
   vector<int> span;
   stack<int> s;
   span.push_back(1);
   s.push(0);
   for(int i=1;i<n;i++){
       if(price[s.top()]>price[i]){s.push(i);span.push_back(1);}
       else{
           while(!s.empty() && price[s.top()]<=price[i]){
               s.pop();
           }
          if(!s.empty()) span.push_back(i-s.top());
          else span.push_back(i+1);
           s.push(i);
           
       }
      
   }
   return span;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends