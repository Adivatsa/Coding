#include<iostream>
#include<vector>

using namespace std;
vector<int> bfsTraversal(int n, vector<pair<int,int>>adj[] )
{
            
        //first store the adjaceny list
        
        //storing the bfs
        vector<int> bfs;
        
        //visited wala array
        vector<int> v(V, 0);
        
        //for different components in this question asking for single componenet
        //U should only consider node directly or indirectly connected to 0
        //for(int i=0; i<V; i++)
       // {
            // if(v[i]!=1)//not visited 
            // {
                queue<int> q;
                q.push(0);
                v[0]=1;
                //print and adjacent child ko daal do queue me
                while(!q.empty())
                {
                    int tempNode=q.front();//push thr first to ans vector
                    q.pop();
                    
                    bfs.push_back(tempNode);
                    //put adjacent child from adj list
                    for(it: adj[tempNode])
                    {
                        if(v[it]!=1)//check it has been not visited then push and mark
                        {
                            q.push(it);
                            v[it]=1;
                        }
                    }
                }
            //}
        //}
        return bfs;
}
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

    bfsTraversal(n , adj);

    return 0;
}