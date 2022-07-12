    #define maxval 1000000
    
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &t)
    {
        //Boundary condition
        if(j<0 || j>=matrix[0].size())
            return maxval;
        
        
        //Base case 
        if(i==0)// we have reached the first row
            return matrix[0][j];
        
        //memoization Step
        if(t[i][j]!=-1)
            return t[i][j];
        
        //call to three sides index, index-1, index+1
        
        int f=matrix[i][j]+ solve(matrix, i-1,j,t);
        int ldg=matrix[i][j]+ solve(matrix, i-1,j-1,t);
        int rdg=matrix[i][j]+ solve(matrix, i-1,j+1,t);
        
        return t[i][j]=min(f, min(ldg, rdg));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        //Recursion  ###TLE  TC=O((3*m)^(n*m)) SC=O(n*m) +O(n)
        
        //Number of rows
        int m=matrix.size();
        
        //Number of column 
        int n=matrix[0].size();
        
//         // we have to return the minimum path sum which can be encountered from top to bottom
//         //we can go from any index to index, index-1, index+1 in next row
//         //we can start from any of m columns
        
//         //memoization #TC=O(n*m) SC=O(n*m)+O(n)
//         vector<vector<int>> t(m, vector<int> (n,-1));
//         int mini=maxval;
//         for(int i=0; i<n; i++)
//             mini=min(mini, solve(matrix, m-1,i,t));
        
//         return mini;
        
//         //Tabulation Approach  TC=O(n*m) SC=O(n*m)
        
//         vector<vector<int>> t(m, vector<int> (n,0));
        
//         //Intialization
//         //intailiza first row values to the dp table
//         for(int i=0; i<n ;i++)
//             t[0][i]=matrix[0][i];
        
//         for(int i=1; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 //same index element
//                 int s=matrix[i][j] + t[i-1][j];
                
//                 //left diagonal index  j-1
//                 int ldg=matrix[i][j];
//                 if(j>0)
//                     ldg=ldg+t[i-1][j-1];
//                 else
//                     ldg+=maxval;
                
//                 //Right diagonal index j+1
//                 int rdg=matrix[i][j];
//                 if(j<n-1)
//                     rdg=rdg+t[i-1][j+1];
//                 else
//                     rdg+=maxval;
                
//                 t[i][j]=min(s, min(ldg, rdg));
//             }
//         }
        
//         //Return the min ans acculmulated at last row
//         int mini=maxval;
//         for(int i=0; i<n; i++)
//             mini=min(mini, t[m-1][i]);
        
//         return mini;
        
        //Space Optimization
        vector<int> prev(n,0);//previous values will be stored
        vector<int> curr(n,0);// current will be filled and next iteration it will become previous
        
        for(int i=0; i<n ;i++)
            prev[i]=matrix[0][i];
        
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //same index element
                int s=matrix[i][j] + prev[j];
                
                //left diagonal index  j-1
                int ldg=matrix[i][j];
                if(j>0)
                    ldg=ldg+prev[j-1];//take value from previous row value stored
                else
                    ldg+=maxval;
                
                //Right diagonal index j+1
                int rdg=matrix[i][j];
                if(j<n-1)
                    rdg=rdg+prev[j+1];//take value from previous row value stored
                else
                    rdg+=maxval;
                
                //Update in current vector
                curr[j]=min(s, min(ldg, rdg));
            }
            prev=curr;
        }
        
        int mini=maxval;
        for(int i=0; i<n; i++)
            mini=min(mini, prev[i]);
        
        return mini;
    }