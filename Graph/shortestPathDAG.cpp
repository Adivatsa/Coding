
//In this question we will implementing single shortest path in DAG
//We have to find out the shortest distance between source to all other nodes in directed acyclic graph
//First we will be finding out topological sort of directed graph
//Because topo sort will shorten the time to start with which node
//As it ensures that before processing that vertex all other precedence has been proessed
//Take input from stack of topo sort and apply BFS to find shortest distance
//check for each node if it is lessr than assigned distance value then update it

//TC=O(n+e) Sc=O(n)
//Step 1: Store adjaceny list for directed graph with weight
//Step 2: Find out the topological order in stack
//Step 3: Make a distance vector assigned with max value and src node with 0
//Step 4: Find if any of the node has reached early then compare the distance with earlier distance
//if less than update this
#include<iostream>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

void toposortdfs(int n, int v, vector<vector<pair<int,int>>>& adj, vector<int>& s, stack<int>& st)
{
    s[n]=1;
    for(auto it: adj[n])
    {
        if(s[it.first]==0)
            toposortdfs(it.first,v,adj,s,st);
    }
    st.push(n);
}
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
    }

    //Storing the topological sort in stack
    stack<int> st;
    vector<int> s(v,0);
    for(int i=0; i<v; i++)
    {
        if(s[i]==0)
            toposortdfs(i,v,adj,s,st);
    }

    //Now topo sort has been stored in stack
    //Now use bfs to find the distance from source node
    //consider source as 0;
    int src=0;

    //create vector to store the distance between source and other nodes 
    vector<int> d(v,INT_MAX);

    d[src]=0;
    //jab tk satck empty na ho jaaye
    while(!st.empty())
    {
        //distance check kar lo agr min hga toh update kar do

        int node=st.top();
        st.pop();

        if(d[node]!=INT_MAX)
        {
            for(auto it: adj[node])
            {
                //check kar lo agr bada distance asssigned hai toh update small distance
                if(d[it.first]> d[node]+it.second)
                    d[it.first]=d[node]+it.second;
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<"Single Source Path from "<<src<< "to "<<i<<" is ";
        if(d[i]==INT_MAX)
            cout<<" Infinity"<<endl;
        else
            cout<<d[i]<<endl;
    }

    return 0;

}