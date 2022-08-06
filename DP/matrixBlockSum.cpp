    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        //first find out the prefix sum matrix 
        //from left to right 
        //then top to bottom
//         vector<vector<int>> t(n, vector<int> (m,0));
//         //from left to right
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(j==0)
//                     t[i][j]=mat[i][j];
//                 else
//                 {
//                     t[i][j]=mat[i][j]+ t[i][j-1];
//                 }
//             }
//         }
//         //from top to bottom
//         for(int i=0; i<m; i++)
//         {
//             for(int j=1; j<n; j++)
//             {
                
//                 t[j][i]=t[j][i]+ t[j-1][i];
//             }
//         }
//         //return t;
        
        //for prefix calculation
        //if first row then add only previous row value
        //if first column then add only previous column value
        //if middle then add previous row and previous column value
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i>0)
                    mat[i][j]+=mat[i-1][j];
                if(j>0)
                    mat[i][j]+=mat[i][j-1];
                if(i>0 && j>0)
                    mat[i][j]-=mat[i-1][j-1];
            }
        }
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //mat[i][j]= t[i+k][j+k]+t[i-k-1][j-k-1] - t[i+k][j-k-1]- t[i-k-1][j+k])
                //here we have to subtract the value for remaning
                //for middle we have to add
                int r0= max(0,i-k);
                int c0=max(0, j-k);
                int r1= min(n-1, i+k);
                int c1= min(m-1, j+k);
                
                ans[i][j]= mat[r1][c1];
                if(r0>0)
                    ans[i][j]-=mat[r0-1][c1];
                if(c0>0)
                    ans[i][j]-=mat[r1][c0-1];
                if(r0>0 && c0>0)
                    ans[i][j]+=mat[r0-1][c0-1];
            }
        }
        return ans;  
    }