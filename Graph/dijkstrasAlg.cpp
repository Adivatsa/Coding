#include<iostream>
#include<queue>
#include<vector>

using namespace std;
//Store the adjaceny list for undirected graph
//use priority queue and implement BFS alg
//
int main()
{
    //First store the weighted adjaceny list
    int v,e;
    cout<<" Entr the number of nodes"<<endl;
    cin>>v;
    cout<<" Entr the number of edges"<<endl;
    cin>>e;

    vector<vector<pair<int,int>>> adj(v);

    for(int i=0; i<e; i++)
    {
        int v,u,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }


    //Now applying bfs algorithm uses priority queue with mean heap

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    //vector to store the min distance from source node
    int src;
    cout<<" Enter the Source Node "<<endl;
    cin>>src;

    vector<int> d(v,INT_MAX);

    d[src]=0;
    q.push({0,src}); //insert into distance, node

    while(!q.empty())
    {
        //take out node and distance from priority queue
        int node=q.top().second;
        int dist=q.top().first;
        q.pop();

        for(auto it: adj[node])
        {
            int newnode=it.first;
            int newwt=it.second;
            //check kar lo yeh agr assigned distance se kam hai toh assign kar do and push into pqueue
            if(d[newnode]> d[node]+newwt)
            {
                d[newnode]= d[node]+newwt;
                q.push({d[newnode],newnode});

            }
        }
    }


    //output

    for(int i=0; i<v; i++)
    {
        cout<<" Shortest Distance from Source "<< src<<" to "<<i<<" is "<<d[i]<<endl;
    }


    return 0;
}