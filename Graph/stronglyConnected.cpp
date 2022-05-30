#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//strongly connected componenets are those jaha from one node we can reach all node
//scc ke liye humlog dfs use karenge
//toposort is used for which kyuki humme nodes finishing time pe chahiye
//humlog toposort ko stack me rakh lenge
//graph ko transpose kar denge
//har ek node from top of stack se dfs lagayenge
//last me ek ek componenet print kar denge

void toposortdfs(int node, vector<int> adj[], stack<int>& st, vector<int>& vis)
{

    vis[node]=1;
    for(auto it: adj[node])
    {
        if(vis[it]==0)
            toposortdfs(it,adj,st,vis);
    }
    st.push(node);
}

void sccdfs(int node, vector<int>& vis, vector<int> transpose[])
{
    vis[node]=1;
    cout<<node<<" ";
    for(auto it: transpose[node])
    {
        if(vis[it]==0)
        {
            sccdfs(it,vis,transpose);
        }
    }
}
int main()
{

    int v, e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i=0; i<e; i++)
    {
        int m,n;
        cin>>m>>n;
        adj[m].push_back(n);
    }

    //finding the toposort
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0; i<v; i++)
    {
        if(vis[i]==0)
            toposortdfs(i,adj,st,vis);
    }

    //Transpose of a graph means reverse the all the directed links
    //adjacent nodes has been insetrd to tranpose array for transpose graph
    vector<int>transpose[v];
    for(int i=0; i<v; i++)
    {
        vis[i]=0;
        for(auto it: adj[i])
            transpose[it].push_back(i);
    }

    //Perform dfs with nodes pop from stack

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(vis[node]==0)
        {
            cout<<" SCC is ";
            sccdfs(node,vis,transpose);
            cout<<endl;
            
        }
        
    }

    return 0;
}