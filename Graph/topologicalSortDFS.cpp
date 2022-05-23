	void topodfs(int n, int V, vector<int> adj[], vector<int> &v, stack<int> &s )
	{
	    //if not been visted mark as visted then go for adjacent nodes
	    v[n]=1;
	    for(auto it: adj[n])
	    {
	        if(v[it]==0)
	        {
	            topodfs(it,V,adj,v,s);
	        }
	    }
	    
	    //it has been visited and all child has been visited push into stack
	    s.push(n);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Topological sort using DFS
	    //Everything is same as dfs alg along with if any call as been returned put 
	    //That node into stack
	    //At last return the stack and pop and return
	    
	    vector<int> v(V,0);
	    stack<int> s;
	    
	    for(int i=0; i<V; i++)
	    {
	        if(v[i]==0)
	            topodfs(i,V,adj,v,s);
	    }
	    
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}