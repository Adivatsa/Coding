#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void sdistancebfs(vector<vector<int>>& adj, int v, int src)
{
    //create a array with first all distance as infinity
    vector<int> d(v,INT_MAX);

    //create a queue and push source into queue
    queue<int> q;
    q.push(src);
    d[src]=0;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it: adj[node])
        {
            if(d[node]+1  < d[it])
            {
                d[it]=d[node]+1;
                q.push(it);

            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<" Distance from Node "<<src<<" to "<<i<< " is "<<d[i]<<endl;
    }

}

int main()
{
    //First Take input and store in adjaceny list
    int v,e;
    cout<<" Enter the number of nodes"<<endl;
    cin>>v;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    //Taking input for undirected graph
    vector<vector<int>> adj(v);

    for(int i=0; i<e; i++)
    {
        int n,m;
        cin>>n>>m;

        adj[m].push_back(n);
        adj[n].push_back(m);
    }

    //Now calling for Shotest distance between source to all other nodes in undirected graph with weight as 1
    int source=0;
    sdistancebfs(adj,v,source);
    
    return 0;
}

