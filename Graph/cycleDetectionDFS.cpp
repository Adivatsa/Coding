  bool cycledfs(int n, int p ,int V, vector<int> adj[], vector<int> &v)
  {
      //mark as visited
      //add all adjacent nodes if not vsisted
      //check if adj node is not parent and marked as 1 then cycle
      
      v[n]=1;
      
      for(auto it: adj[n])
      {
          if(v[it]!=1)
          {
                if(cycledfs(it,n,V,adj,v)==true)
                    return true;
          }
          else if(it!=p)//it has been visited and also it is not parent
                    return true;
      }
      return false;
  }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {

        //Using DFS
        
        //create a visited array for mark intial as 0 and call dfs with node and parent
        
        vector<int> v(V,0);
        for(int i=0; i<V; i++)
        {
            if(v[i]!=1)
            {
                if(cycledfs(i,-1,V,adj,v)==true)
                    return true;
            }
            
        }
        return false;
    }