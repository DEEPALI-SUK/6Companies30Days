class Solution {
public:
    bool dfs(int i,int j, string &w, vector<vector<char>>& b,int idx){
        if(idx==w.length()-1)return true;
        b[i][j]-=65;
        if(i>=1 && b[i-1][j]==w[idx+1] && dfs(i-1,j,w,b,idx+1))return true;
        if(i+1<b.size() && b[i+1][j]==w[idx+1] && dfs(i+1,j,w,b,idx+1))return true;
        if(j>=1 && b[i][j-1]==w[idx+1] && dfs(i,j-1,w,b,idx+1))return true;
        if(j+1<b[0].size() && b[i][j+1]==w[idx+1] && dfs(i,j+1,w,b,idx+1))return true;
        b[i][j]+=65;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int r=b.size(),c=b[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]==w[0] && dfs(i,j,w,b,0))return true;
            }
        }
        return false;
    }
};