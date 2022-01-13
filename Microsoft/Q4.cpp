#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > A, int m, int n) 
    {
        // code here 
        vector<int> v;
        int k = 0, l = 0;
       while (k < m && l < n)  
     {
        /* Print the first row from the remaining rows */
        for (int i=l;i< n;i++){
            v.push_back(A[k][i]);
        }
        k++;
  
        /* Print the last column from the remaining columns */
        for (int i = k;i< m;i++){
           v.push_back(A[i][n-1]);
        }
        n--; 
  
        /* Print the last row from the remaining rows */
        if ( k < m) 
        {
            for (int i = n-1; i >= l; --i){   
                v.push_back(A[m-1][i]);
            }
            m--;
        }
  
        /* Print the first column from the remaining columns */
        if (l < n) 
        {
            for (int i = m-1; i >= k; --i){   
                v.push_back(A[i][l]);
            }
            l++;
        }
      }
      return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends