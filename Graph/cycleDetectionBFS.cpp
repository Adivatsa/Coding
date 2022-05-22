bool cyclebfs(int n, int V, vector<int> adj[], vector<int> &v)
  {
      //in this bfs we will store node and parent in queue
      //if visted and not parent it means that cycle is there
      
      queue<pair<int,int>> q;
      v[n]=1;
      q.push({n,-1});//first element pair is -1
      
      while(!q.empty())
      {
          //take out the node
          int node =q.front().first;
          //take out the parent
          int parent=q.front().second;
          
          q.pop();
          //check for adjacent nodes
          for(auto it: adj[node])
          {
              if(v[it]!=1)
              {
                  q.push({it,node});
                  v[it]=1;
              }
              else if(it!=parent)//this means visited and also not parent means both child
                return true;
          }
      }
      return false;//queue is empty nothing found
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        //make a visited array and traverse if not visited
        //if return true then cycle otherwise no cycle
        vector<int> v(V,0);
        for(int i=1; i<V; i++)
        {
            if(v[i]!=1)
                if(cyclebfs(i,V,adj,v)==true)
                    return true;
        }
        return false;
    }