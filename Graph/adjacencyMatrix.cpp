#include<iostream>
#include<map>

using namespace std;

//Space Complexity=O(n^2)

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
    //Creation of nxn adjacency matrix
    int adj[n+1][n+1];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adj[i][j]=0;
        }
    }
    //Take input of edges
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>> u>>v;;
        adj[u][v]=1;
        if(isdirected==0)
            adj[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


