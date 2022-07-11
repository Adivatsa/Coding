//     int totalUniquePath(int m, int n, vector<vector<int>>&t)
//     {
//         //base case 
//         //when it raeches at top left corner just return 1
//         //when it goes out of boundary just return 0
//         //otherwise count all the unique by going left and going up
        
//         if(m==0 && n==0)
//             return 1;//only one path as u ahve reached
        
//         if(m<0 || n<0)
//             return 0;//no path
        
//         //Applying Memoization
//         if(t[m][n]!=-1)
//             return t[m][n];
        
//         int leftside=totalUniquePath(m, n-1,t);
//         int upside=totalUniquePath(m-1,n,t);
        
//         //return the total unique path
//         t[m][n]=leftside + upside;
//         return t[m][n];
//     }
    
    int uniquePaths(int m, int n) {
        
       //Recursion  #TLE
        
        // //use Memoization
        // vector<vector<int>> t(m, vector<int>(n,-1));
        // return totalUniquePath(m-1,n-1,t); 
        
//         //Bottom up Tabulation Approach
//         vector<vector<int>> t(m,vector<int>(n));
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 //Base case 
//                 if(i==0 && j==0)
//                 {
//                     t[i][j]=1;
//                     continue;
//                 }    
//                     //check for down and right path and store it in that position
//                     int down=0;
//                     int right=0;
//                     if(i>0)
//                         down=t[i-1][j];
//                     if(j>0)
//                         right=t[i][j-1];
    
//                     t[i][j]=down + right;
                
//             }
//         }
//         return t[m-1][n-1];
        
        //Space optimization
        
        //it will contain the previous row value
        vector<int> up(n,0);
        for(int i=0; i<m; i++)
        {
            //it will store the current row from left to right
            vector<int> curr(n);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=1;
                    continue;
                }
                int down=0;
                int right=0;
                
                if(i>0)//we need value from previous row
                    down=up[j];
                if(j>0)//we need value in current roe previous value
                    right=curr[j-1];
                //update the current value
                curr[j]=down+right;
            }
            //current will make as previous row and start iterating
            up=curr;
        }
        //return last eleemnt
        return up[n-1];
        
    }