	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    //Topological sort using BFS algorithm
    //Kahn's Algorithm
    //Step 1: Store the indegree of evry node
    //Step 2: Iterate over indegree array and push node which has indegree as 0
    //Step 3: Print that node and pop from queue
    //Step 4: For that node make adjacent nodes indegree decrement
    //Step 5: if any adjacent node has indegree as 0 then push it
    
    //Create indegree array with all 0
    vector<int> in(V,0);
    queue<int> q;
    
    for(int i=0; i<V ; i++)//for every node
    {
        for(auto it: adj[i])//find adjacent nodes and mark its indegree+1 U->v there v is adjacent node
                in[it]++;
    }
    
    //Step 2: Iterate over indegree array and push node which has indegree as 0
    for(int i=0; i<V; i++){
        if(in[i]==0)
            q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        //Step 3: Print that node and pop from queue
        int node=q.front();
        q.pop();
        ans.push_back(node);
        //Step 4: For that node make adjacent nodes indegree decrement
        for(auto it: adj[node])
        {
            in[it]--;
            //Step 5: if any adjacent node has indegree as 0 then push it
            if(in[it]==0)
                q.push(it);
        }
    }
    return ans;
	}