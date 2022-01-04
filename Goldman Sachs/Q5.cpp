# include<bits/stdc++.h> 
using namespace std; 
  
/* Function to get the nth ugly number*/
unsigned long long getNthUglyNo(unsigned long long n) 
{ 
    unsigned long long ugly[n]; // To store ugly numbers 
    unsigned long long i2 = 0, i3 = 0, i5 = 0; 
    unsigned long long next_multiple_of_2 = 2; 
    unsigned long long next_multiple_of_3 = 3; 
    unsigned long long next_multiple_of_5 = 5; 
    unsigned long long next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (unsigned long long i=1; i<n; i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, 
                           min(next_multiple_of_3, 
                               next_multiple_of_5)); 
       ugly[i] = next_ugly_no; 
       if (next_ugly_no == next_multiple_of_2) 
       { 
           i2 = i2+1; 
           next_multiple_of_2 = ugly[i2]*2; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
           i3 = i3+1; 
           next_multiple_of_3 = ugly[i3]*3; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = ugly[i5]*5; 
       } 
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
	    unsigned long long n;
	    cin>>n;
    cout << getNthUglyNo(n)<<endl; 
    
    }
}