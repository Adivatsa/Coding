    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        //Same as Rotten oranges
        
        //Number of rows
        int n=mat.size();
        //number of column
        int m=mat[0].size();
        //create output matrix with all as -1
        vector<vector<int>> t(n, vector<int> (m,-1));
        
        //To apply bfs use queue to store cordinates
        queue<pair<int, int>> q;
        
        //Traverse and put all the cordintes having 0 and assign value
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    t[i][j]=0;
                }
            }
        }
        
        //for traversal into four direction
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            //Trvaersing into four direction
            for(int i=0; i<4; i++)
            {
                int nx=x+dx[i];
                int ny=y+ dy[i];
                //check for valid where in given matrix is 1 and in ans matrix has -1 value
                if(nx>=0 && ny>=0 && nx<=n-1 && ny<=m-1 && mat[nx][ny]==1 && t[nx][ny]==-1)
                {
                    //put the value with distance from 0
                    t[nx][ny]= 1+ t[x][y];
                    q.push({nx,ny});
                }
            }
        }
        return t;
        
    }