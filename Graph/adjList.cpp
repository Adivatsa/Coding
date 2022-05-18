#include<iostream>
#include<vector>

using namespace std;


//Incase of undirected graph the complexity is O(n+2E)
//Incase of undirected graph the complexity is O(n+E)
int main()
{
    int n,m;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;
    cout<<"Enter the Number of Edges"<<endl;
    cin>>m;
    int isdirected;
    cout<<"It is a Directed Graph "<<endl;
    cin>>isdirected;

    //Creation of Adjaceny list of size n
    vector<pair<int,int>>adj[n];

    //Insertion of edges
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        
        if(isdirected==0)
        {
            cin>>u >>v;
            adj[u].push_back({v,0});
            adj[v].push_back({u,0});
        }
        else
        {
            cin>>u >>v>>wt;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j].first<<" ";
            if(isdirected==1)
                cout<<adj[i][j].second;
        }
        cout<<endl;
    }

    return 0;
}