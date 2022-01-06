class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size(),mx=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==2)q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int>p=q.front();
            q.pop();
            
            int i=p.first.first,j=p.first.second;
            //cout<<i<<" "<<j<<" "<<mx<<endl;
            if(i+1<n && a[i+1][j]==1){
                a[i+1][j]=2;
                q.push({{i+1,j},p.second+1});
                mx=max(mx,p.second+1);
            }
            if(i-1>=0 && a[i-1][j]==1){
                a[i-1][j]=2;
                q.push({{i-1,j},p.second+1});
                mx=max(mx,p.second+1);
            }
            if(j+1<m && a[i][j+1]==1){
                a[i][j+1]=2;
                q.push({{i,j+1},p.second+1});
                mx=max(mx,p.second+1);
            }
            if(j-1>=0 && a[i][j-1]==1){
                a[i][j-1]=2;
                q.push({{i,j-1},p.second+1});
                mx=max(mx,p.second+1);
            }
        }
        int l=0;
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    l=1;
                    mx=-1;
                    break;
                }
            }
            if(l)break;
        }
        return mx;
    }
};