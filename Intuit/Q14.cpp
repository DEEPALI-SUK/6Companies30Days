class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int n=g.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0||q.size()==n*n) return -1;
        int d1[]={-1,1,0,0};
        int d2[]={0,0,-1,1};
        int ans=0;
        while(!q.empty()){
            int s=q.size(); 
            while(s--){
                pair<int,int> p=q.front();
                int x=p.first,y=p.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int k=x+d1[i],l=y+d2[i];
                    if(k>=0 && k<n && l>=0 && l<n && g[k][l]==0){
                        g[k][l]=1;
                        q.push({k,l});                    
                    }
                }
           }      
           ans++;
        }
        return ans-1;
    }
};