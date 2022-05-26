#include<iostream>
#include<set>
#include<vector>

using namespace std;
vector<pair<int,int>> p; //{parent,rank}

//Disjoint set is a DS used to find whether they belongs to same componenet
//Find and union are operations inside the disjoint set
//Find operation is used to find wheteher they belongs to same set or not using parent 
//If both element has same parent then they belong to same set
//Union is used merge two sets to 1
//Union of two elements with same parent leads to cycle in graph

//Detect Cycle in undirected graph using disjoint set
//TC=O(n*e) for each edge go for find n nodes

//Not able to detect for directed graph bcz set don't have any direction


//for path compression use when anyone is parent just assign the value
//for union by rank if both has same rank then increse rank and connect anyone
//otherwise just connect which has higher rank to smaller rank

int find(int node)//finding the parent
{
    if(p[node].first==-1)//we know that parent ahs always value as -1 if found return element
        return node;
    
    //this element is not parent jao ish element ke papa ko khoj ke le aao
    return p[node].first=find(p[node].first);
}

void callunion(int n1, int n2)
{
    // n1=find(n1);
    // n2=find(n2);
    //parent[n1]=n2;

    //n1 rank is greater than n2
    if(p[n1].second > p[n2].second)
        p[n1].first=n2;
    else if(p[n1].second < p[n2].second)
        p[n2].first=n1;
    else
    {
        //same rank of both then connect anyone and increase the rank
        p[n2].first=n1;
        p[n1].second+=1;
    }
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
     p.resize(v,{-1,0});//{parent,rank}

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