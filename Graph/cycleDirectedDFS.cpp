bool cycledfs(int n, int V, vector<int> adj[], vector<int> &v, vector<int> &dfs)
    {
        //mark in both dfs and visted array as 1 
        //Check for adjacent nodes 
        //if not visted then call dfs alg
        //if visted is 1 and dfs array is 1 for any adjacent node then cycle is there
        //returning from call  make dfs array as 0
        
        v[n]=1;//make both as visited as 1
        dfs[n]=1;
        
        for(auto it: adj[n])
        {
            if(v[it]==0)//not been visted so call dfs alg
            {
                if(cycledfs(it,V,adj,v,dfs)==true)
                    return true;
            }
            else if(dfs[it]==1)//visted array is 1 and dfs array is 1 i.e. cycle is there
                return true;
        }
        
        dfs[n]=0;//make dfs arrays as 0 
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        //Using DFS
        
        vector<int> v(V,0);
        vector<int> dfs(V,0);
        
        //check for all componenets if not marked visited then call dfs
        for(int i=0; i<V; i++)
        {
            if(v[i]==0)
            {
                if(cycledfs(i,V,adj,v,dfs)==true)
                    return true;
            }
        }
        return false;
    }