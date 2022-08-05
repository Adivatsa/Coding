    int maximalSquare(vector<vector<char>>& matrix) {
    
        //Number of rows
        int n=matrix.size();
        //Number of columns
        int m=matrix[0].size();
        
        //this dp table will contain how many consecutive sqaure we can make
        //we will check up , left, up left corner and add +1 if it is 1
        //for the first row u can just check directly
        vector<vector<int>> t(n, vector<int>(m,0));
        int res=0;
        for(int i=0; i<n ;i++)
        {
            for(int j=0; j<m; j++)
            {
                //for the first row and column
                if(i==0 || j==0)
                {
                   if(matrix[i][j]=='1')
                        t[i][j]=1; 
                }
                else
                {
                    if(matrix[i][j]=='1')
                        t[i][j]=min({t[i-1][j-1], t[i-1][j], t[i][j-1]}) +1;
                }
                res=max(res, t[i][j]);
            }
        }
        return res* res;
        
    }