class Solution {
public:
    Node* func(vector<vector<int>>& grid,int r_st,int r_ed,int c_st,int c_ed,int x)
    {
        int sum=0;
        for(int i=r_st;i<r_ed;i++)
        {
            for(int j=c_st;j<c_ed;j++)
            {
                sum+=grid[i][j];
            }
        }
        Node* res;
        if(sum==0)
            res=new Node(false,true);
        else if(sum==(x*x))
            res=new Node(true,true);
        else
        {
            res=new Node(false,false);
            x/=2;
            res->topLeft = func(grid,r_st,r_st+x,c_st,c_st+x,x);
            res->topRight = func(grid,r_st,r_st+x,c_st+x,c_ed,x);
            res->bottomLeft = func(grid,r_st+x,r_ed,c_st,c_st+x,x);
            res->bottomRight = func(grid,r_st+x,r_ed,c_st+x,c_ed,x);
        }
        return res;
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* res = func(grid,0,n,0,n,n);
        return res;
    }
};