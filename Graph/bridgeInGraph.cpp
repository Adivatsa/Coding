#include<iostream>
#include<vector>

using namespace std;

void bridgedfs(int n, int p, vector<vector<int>>&adj, vector<int>&tim, vector<int>&low, vector<int>&vis, int &timer)
{

    //Steps:
    //assign tim , low with timer
    //check for adjacent nodes
    //if adj node is parent dont call dfs
    //if not visited then call dfs 
    //after returing from dfs check it low with all adjacent nodes
    //check if low(it)> tim(node) it is bridge
    //it has been visited tand not parent then just update ur low and ereturn

    tim[n]=low[n]=timer++;
    vis[n]=1;
    for(auto it: adj[n])
    {
        if(it==p)
            continue;
        if(vis[it]==0)
        {
            bridgedfs(it,n,adj,tim,low,vis,timer);
            low[n]=min(low[n], low[it]);
            if(low[it]> tim[n])
                cout<<" Bridge from "<<n<<" to "<<it<<endl;
        }
        else
            low[n]=min(low[n], tim[it]);

    }
}
int main()
{
    int v,e;
    cout<<" Enter the Number of Nodes "<<endl;
    cin>>v;
    cout<<" Enter the Number of Edges "<<endl;
    cin>>e;

    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++)
    {
        int m,n;
        cin>>m>>n;

        adj[m].push_back(n);
        adj[n].push_back(m);

    }

    //create vector array for tim, low, visted
    vector<int> tim(v,-1);
    vector<int> low(v,-1);
    vector<int> vis(v,0);

    int timer=0;

    for(int i=0; i<v; i++)
    {
        if(vis[i]==0)
            bridgedfs(i,-1,adj,tim,low,vis,timer);
    }

    return 0;

}