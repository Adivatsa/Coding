void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
  {
      //check for boundary condition and if it is 1
      if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1')
            return;
        
        //mark with 2 if it is 1
        grid[i][j]='2';
        
        //total 8 direction movement
        //left
        dfs(grid,i,j-1,m,n);
        //right
        dfs(grid,i,j+1,m,n);
        //up
        dfs(grid,i-1,j,m,n);
        //down
        dfs(grid,i+1,j,m,n);
        //left up
        dfs(grid,i-1,j-1,m,n);
        //left down
        dfs(grid,i+1,j-1,m,n);
        //right up
        dfs(grid,i-1,j+1,m,n);
        //right down
        dfs(grid,i+1,j+1,m,n);
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        //in this if all 1 are connectd make one island
        //apply dfs and see how many componenet and increase the count variable
        
        int m=grid.size();//row
        int n=grid[0].size();//column
        
        if(m==0 ||n==0)
            return -1;
        
        int island=0;    
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //check if it is 1 then call dsf
                if(grid[i][j]=='1')
                {
                    //call for dfs 
                    dfs(grid,i,j,m,n);
                    island++;
                }
            }
        }
        return island;
    }