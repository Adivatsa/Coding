bool bipartitedfs(int n, int V, vector<int>adj[], vector<int> &c  )
    {
        for(auto it: adj[n])//check for adjacent nodes if not marked any color then call dfs otherwise check color is same or differenrt 
        {
            if(c[it]==-1)
            {
                c[it]=1-c[n];
                if(!bipartitedfs(it,V,adj,c))
                    return false;
            }
            else if(c[it]==c[n])//same color then return false
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    //Using DFS to find graph is bipartite or not
	    vector<int> c(V,-1);
	    for(int i=0; i<V; i++)
	    {
	        if(c[i]==-1)//if not marked any color then mark color and call dfs
	        {
	            c[i]=1;
	            if(!bipartitedfs(i,V,adj,c))
	                return false;
	        }
	    }
	    /*if(!bipartitedfs(0,V,adj,c))
	        return false;
	   else*/
	        return true;
	}