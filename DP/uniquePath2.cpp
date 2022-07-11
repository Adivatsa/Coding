    int uniquepath(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&t)
    {
        
        //if it is obstacle then do not proceed
        if(i<0 || j<0 || grid[i][j]==1)
            return 0;
        
        //otherwise find the total unique path
        //base case 
        //when we reached to 0,0 then return 1;
        if(i==0 && j==0)
            return 1;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int up=uniquepath(i-1,j,grid,t);
        int left=uniquepath(i,j-1,grid,t);
        
        

        return t[i][j]=left+up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        //Recursive solution
        //rows
        int m=obstacleGrid.size();
        //column
        int n=obstacleGrid[0].size();
        //Memoization
        vector<vector<int>> t(m,vector<int>(n,-1));
        return uniquepath(m-1, n-1, obstacleGrid,t);
        
        //Tabulation is same as unique path 1 only one extra line for obstacle
    }