//     int solve(vector<vector<int>>& grid, int i, int j1, int j2, int m, int n, vector<vector<vector<int>>>&t)
//     {
//         if(j1<0 || j2<0 || j1>=n || j2>=n )
//             return 0;
        
//         if(i==m-1)
//         {
//             if(j1==j2)//they reach at same index at alst column
//                 return grid[i][j1];
//             else
//                 return grid[i][j1]+ grid[i][j2];
//         }
        
//         if(t[i][j1][j2]!=-1)
//             return t[i][j1][j2];
        
//         int maxi=0;
//         //total 9 movements with each has movement to (i-1, i, i+1) to(j-1,j,j+1)
//         for(int k1=-1; k1<=1; k1++)
//         {
//             for(int k2=-1 ; k2<=1; k2++)
//             {
//                 //call to function
//                 int value=solve(grid,i+1,j1+k1,j2+k2,m,n,t);
//                 //check if they both have picked the same cheery 
//                 if(j1==j2)
//                     value+=grid[i][j1] ; 
//                 else
//                 {
//                     value+=grid[i][j1]+ grid[i][j2];
//                 }
//                 maxi=max(value, maxi);
//             }   
//         }        
//         return t[i][j1][j2]=maxi;
//     }
    int cherryPickup(vector<vector<int>>& grid) {
        
        //Recursion
        
        //Number of rows
        int m=grid.size();
        //Number of column 
        int n=grid[0].size();
        
        //Memoization
        // vector<vector<vector<int>>> t(m,vector<vector<int>> (n, vector<int>(n,-1)));
        // return solve(grid, 0, 0,n-1,m,n,t);
        
        //Bottom up or Tabulation Approach
        
        vector<vector<vector<int>>> t(m,vector<vector<int>> (n, vector<int>(n,0)));
        
        for(int j1=0 ; j1<n ; j1++)
        {
            for(int j2=0; j2<n; j2++)
            {
                if(j1==j2)
                    t[m-1][j1][j2]=grid[m-1][j1];
                else
                    t[m-1][j1][j2]=grid[m-1][j1]+ grid[m-1][j2];
            }
        }
        
        
        for(int i=m-2; i>=0; i--)
        {

            for(int j1=0 ; j1<n ; j1++)
            {
                for(int j2=0; j2<n; j2++)
                {
                    int maxi=0;
                    //total 9 movements with each has movement to (i-1, i, i+1) to(j-1,j,j+1)
                    for(int k1=-1; k1<=1; k1++)
                    {
                        for(int k2=-1 ; k2<=1; k2++)
                        {
                            int ans=0;
                            if (j1 == j2)
                                    ans = grid[i][j1];
                            else
                                    ans = grid[i][j1] + grid[i][j2];

                            if (j1 + k1>=0  && j1 + k1 < n && j2 + k2 >= 0 && j2 + k2 <n)
                                ans += t[i + 1][j1 + k1][j2 + k2];
                            else
                                ans += -1e9;
                            maxi = max(ans, maxi);
                        }   
                    }
                    t[i][j1][j2]=maxi;
                }
            }
        }
        return t[0][0][n-1]; 
    }