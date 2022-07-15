    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int &count)
    {
        //Base case
        if(i<0 || j<0 || i>=m || j>=n)//out of bound 
            return ;
        
        //if it has been found that it is water then just return 
        if(grid[i][j]==0)
            return;
        
        //Increment the area
        count++;
        
        //Make it as 0 ,it has been added in area so that we can traverse twice
        grid[i][j]=0;
        
        dfs(grid,m, n, i+1,j , count);//UP
        dfs(grid,m, n, i, j+1, count);//RIGHT
        dfs(grid,m, n, i, j-1, count);//LEFT
        dfs(grid,m, n, i-1, j, count);//DOWN
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        //in this we have to find the max area of island which contains formed by only 1's
        //we will got to location where 1 is present and make dfs call to up, below, left and right
        //then if found 1 then make it as 0 and inc count
        //fidn every time maximum and return it
        //no of rows
        int m=grid.size();
        
        //no of columns
        int n=grid[0].size();
        
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    
                    //Make dfs call if found as 1
                    dfs(grid,m, n, i ,j , count);
                    
                    //find maximum area of island
                    ans=max(ans, count);
                }  
            }
        }
        return ans; 
    }