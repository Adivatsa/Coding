int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    
    
    //Graph Creation for adjacent list with node,weight   
    vector<vector<int>>adj[n+1];   
    for(int j=0;j<times.size();j++)   // Graph creation
    {
                int u=times[j][0];
                int v=times[j][1];
                int w=times[j][2];
                adj[u].push_back({v,w});
    }

    //vector to store the min distance from source node
        vector<int> d(n+1,100000);

    d[k]=0;
    q.push({0,k}); //insert into distance, node

    while(!q.empty())
    {
        //take out node and distance from priority queue
        int node=q.top().second;
        int dist=q.top().first;
        q.pop();

        for(auto it: adj[node])
        {
            int newnode=it[0];
            int wt=it[1];
            //
            //check kar lo yeh agr assigned distance se kam hai toh assign kar do and push into pqueue
            if(d[newnode]> d[node]+wt)
            {
                d[newnode]= d[node]+wt;
                q.push({d[newnode],newnode});

            }
        }
    }
        
        int res = 0;
        for(int i=1 ;i<=n; i++){
            if(d[i] == 100000){
                //cout<<i;
                return -1;
            }
            else
                res = max(res, d[i]);
        }
        return res;
        
        
        
    }