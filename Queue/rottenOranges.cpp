    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time=0;
        if(grid.size()==0)
            return 0;
        
        //rows
        int m=grid.size();
        //column
        int n=grid[0].size();
        //Total tomatos
        int total=0;
        //count of tomato traversed
        int cnt=0;
        //queue to store the address of rooten tomatos
        queue<pair<int,int>>q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]!=0)
                    total++;
                //insert rotten into queue
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        //we have to traverse into four direction up,down,left ,right to rott tomato
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        //left side -1,0  right 1,0 up 0,1  down 0,-1
        
        //traverse it we will have rotten oragnges
        while(!q.empty())
        {
            //find number of rotten oranges
            int ro=q.size();
            //increase in current rotten size
            cnt+=ro;
            //jab tak rotten oranges inside queue process it
            while(ro--)
            {
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                for(int i=0; i<4; i++)
                {
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
                
            }
            //this means it has rotten some oranges so increase one unit time
            if(q.size()>0)
                    time++;
        }
        //if cnt is equal to total means all oranges has been traversed
        if(cnt==total)
                return time;
            else
                return -1;
    }