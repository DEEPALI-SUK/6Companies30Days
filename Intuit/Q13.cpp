class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
         int n=g.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                if(g[i][j]==1)break;
                c++;
            }
            v.push_back(c);
        }
        int k=0,ans=0;
        while(k<n){
            int d=n-1-k;
            if(v[k]<d){
                int j=-1;
                for(int i=k+1;i<n;i++){
                    if(v[i]>=d){
                        j=i;
                        break;
                    }
                }
                if(j==-1)return j;
                ans+=j-k;
                int t=v[j];
                for(int i=j;i>k;i--)v[i]=v[i-1];
                v[k]=t;
            }
            k++;
        }
        return ans;
    }
};