#include<iostream>
#include<set>
#include<vector>

using namespace std;
vector<int> parent;

//Disjoint set is a DS used to find whether they belongs to same componenet
//Find and union are operations inside the disjoint set
//Find operation is used to find wheteher they belongs to same set or not using parent 
//If both element has same parent then they belong to same set
//Union is used merge two sets to 1
//Union of two elements with same parent leads to cycle in graph

//Detect Cycle in undirected graph using disjoint set
//TC=O(n*e) for each edge go for find n nodes

//Not able to detect for directed graph bcz set don't have any direction

int find(int node)//finding the parent
{
    if(parent[node]==-1)//we know that parent ahs always value as -1 if found return element
        return node;
    
    //this element is not parent jao ish element ke papa ko khoj ke le aao
    return find(parent[node]);
}

void callunion(int n1, int n2)
{
    // n1=find(n1);
    // n2=find(n2);
    parent[n1]=n2;
}

bool iscycle(vector<pair<int,int>>& adj )
{
    //Check for all the nodes which are in adjaceny list
    for(auto it: adj)
    {
        //find the parent of both of the elements 
        //If parents are same then cycle exists otherwise combine in one union by making one as parent
        int a=find(it.first);
        int b=find(it.second);

        if(a==b )
            return true;

        callunion(a,b); //union of two sets done using assigning one as a parent
    }
    return false;
}
int main()
{

    //Take input for adjaceny list of undirected graph with (u,v)
    int v,e;
    cout<<" Enter the number of nodes "<<endl;
    cin>>v;


    cout<<" Enter the number of edges "<<endl;
    cin>>e;

    

    vector<pair<int,int>> adj;
    for(int i=0; i<e; i++)
    {
        int m,n;
        cin>>m>>n;
        adj.push_back({m,n});
    }

    //Everyone is Parent of itself
     parent.resize(v,-1);

    //for detction of cycle 
    if(iscycle(adj))
    {
        // for(int i=0; i<v; i++)
        //     cout<<parent[i];
        cout<<" True Cycle exists"<<endl;
    }
        
    else
        cout<<" Cycle is not there "<<endl;

    return 0;
}