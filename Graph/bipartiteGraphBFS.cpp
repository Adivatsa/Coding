bool bipartiteBFS(int n, vector<vector<int>> &graph, int V, vector<int> &col)
    {
        //node ko color kar do and queue me push kar do
        queue<int> q;
        col[n]=0;
        q.push(n);
        
        while(!q.empty())
        {
            //node nekl lo
            int curr=q.front();
            q.pop();
            //adjaent nodes ko queue me daal do agr colored nai hai toh
            for(auto it: graph[curr])
            {
               if(col[it]==-1)//agr colored nai hai toh color kar do opposite se aur push kar do
               {
                   col[it]=1-col[curr];
                   q.push(it);
               }
                else if(col[it]==col[curr])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        //We have to find for different components
        int V=graph.size();
        vector<int> col(V,-1);
        
        for(int i=0; i<V; i++)
        {
            if(col[i]==-1)
                if(!bipartiteBFS(i,graph,V,col))
                    return false;
            
        }
        return true;
        
    }