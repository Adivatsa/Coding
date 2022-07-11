    #define maxval 1000
    int solve(vector<vector<int>>&g, int i, int j, vector<vector<int>> &t)
    {
        
        //base case
        if(i==0 &&j==0)
            return g[i][j];
        
        if(i<0 || j<0)
            return maxval;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        //we have to move up or left to reach 0,0
        //for left tke current and go in left
        int left=g[i][j]+ solve(g, i,j-1,t);
        
        int up=g[i][j] + solve(g, i-1, j,t);
        
        
        return t[i][j]=min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        //Recursive solution
        //rows
        int m=grid.size();
        //column
        int n=grid[0].size();
        
        // //memoization
        // vector<vector<int>> t(m, vector<int> (n,-1));
        // return solve(grid, m-1, n-1,t);
        
        //Tabulation method
        vector<vector<int>> t(m, vector<int> (n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {

                if(i==0 && j==0)
                {

                    t[i][j]=grid[i][j];
                    continue;
                }
                int left=grid[i][j];
                int up=grid[i][j];
                if(j>0)//consider the path
                    left=left+t[i][j-1];
                else//in this case neglect the path
                    left+=maxval;
                if(i>0)//consider the path
                    up+=t[i-1][j];
                else//neglect the path
                    up+=maxval;
                
                //return the minimum of both these two
                t[i][j]=min(left,up);
            }
        }
        return t[m-1][n-1];
        
    }