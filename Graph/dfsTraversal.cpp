   void dfsgraph(int s,int V, vector<int> adj[],vector<int> &dfs,vector<int> &v)
    {
        dfs.push_back(s);
        v[s]=1;
        for(auto it: adj[s])
        {
            if(v[it]!=1)
                dfsgraph(it,V,adj,dfs,v);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       
       
       //alg: DFS will be recursive approach as uses stack
       //assign all visited to 0
       //start from first and continue till last
       //Just take out adjacent nodes and call recursively over it
       vector<int> dfs;
       vector<int> v(V,0);
       //For multiple componenets use for loop from 0 to n-1 and if not visited call them
       //here for only one componenet
       dfsgraph(0,V,adj,dfs,v);
       
       return dfs;
    }


\