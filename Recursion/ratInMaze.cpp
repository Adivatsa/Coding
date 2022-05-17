void solve(vector<vector<int>> &m, int n, int x, int y, vector<string> &ans,
    string path,vector<vector<int>> v)
    {
        //base condition 
        //when reaches to last
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        //4 types of movements
        v[x][y]=1;//mark visited
        //up
        int xx=x-1;
        int yy=y;
        //check it should lie inside range of matrix and not be visited abd also value should be 1 
        if((xx>=0 && xx<n) &&(yy>=0 && yy<n) && v[xx][yy]==0 && m[xx][yy]==1)
        {
            path.push_back('U');
            solve(m,n,xx,yy,ans,path,v);
            path.pop_back();//for any new path not to repeat
        }
        
        //down
        xx=x+1;
        yy=y;
        if((xx>=0 && xx<n) &&(yy>=0 && yy<n) && v[xx][yy]==0 && m[xx][yy]==1)
        {
            path.push_back('D');
            solve(m,n,xx,yy,ans,path,v);
            path.pop_back();
        }
        
        //left
        xx=x;
        yy=y-1;
        if((xx>=0 && xx<n) &&(yy>=0 && yy<n) && v[xx][yy]==0 && m[xx][yy]==1)
        {    
            path.push_back('L');
            solve(m,n,xx,yy,ans,path,v);
            path.pop_back();
        }
        //right
        xx=x;
        yy=y+1;
        if((xx>=0 && xx<n) &&(yy>=0 && yy<n) && v[xx][yy]==0 && m[xx][yy]==1)
        {
            path.push_back('R');
            solve(m,n,xx,yy,ans,path,v);
            path.pop_back();
        }
        
        
        //mark as not visited
        
        v[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Rat ko 0,0 se n-1,n-1 jana hai 
        //ish bich me woh left, right ,up and down ja sakta hai
        //up means x-1,y down x+1,y  left me x,y-1  right x,y+1
        //ek matrix banna lenge jaha visited mark karenge jisse ulta whi laut ke na jaaye
        //koi bhi position pahuchte he visted ko 1 kar do
        //laute waqt usko 0 mark kar dena
        
        string path="";//to store the path
        
        vector<string> ans;
        
        if(m[0][0]==0)
            return ans;
        vector<vector<int>> v=m;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                    v[i][j]=0;
        
        
        solve(m,n,0,0,ans,path,v);
        sort(ans.begin(), ans.end());
        return ans;
    }