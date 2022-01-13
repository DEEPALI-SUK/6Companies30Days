//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat)
{
    // Your code goes here
    int n=mat.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int t=mat[i][j];
            mat[i][j]=mat[j][n-i-1];
            mat[j][n-i-1]=mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j]=mat[n-1-j][i];
            mat[n-1-j][i]=t;
        }
    }
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
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends