#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct node
    {
        int u,v,wt;
        //Constructor
        node(int a, int b, int weight)
        {
            u=a;
            v=b;
            wt=weight;
        }
    };

//Bellaman ford is useed to find the shortest distance between source to all other nodes
//it is applicable to nodes having negative cycle
//TC=O(n-1)*O(e)
//steps:
//First step store the adjaceny list with inside a class or structure
//Apply realx formulae for n-1 i.e. node-1 times
//take flag= false and apply onr more time if value changes it means that negative cycle is there
//otherwise the print the nodes
int main()
{
    int n,e;

    cout<<" Enter the number of Nodes "<<endl;
    cin>>n;
    cout<<" Enter the number of edges "<<endl;
    cin>>e;

    //Storing into struct node strting ending node and edge wieght
    vector<node> adj;
    for(int i=0; i<e; i++)
    {
        int m,o,wtt;
        cin>>m>>o>>wtt;
        adj.push_back(node(m,o,wtt));
    }

    //Source node
    int src;
    cin>>src;

    vector<int> d(n,1000000);
    d[src]=0;//Source will have always 0 as distance 

    //Apply realaxation for n-1 times
    for(int i=1; i<n; i++)
    {
        for(auto it: adj)
        {
            if(d[it.u]+it.wt < d[it.v])
                d[it.v]=d[it.u]+it.wt;
        }
    }

    //Checking for negative cycle so apply one more time relaxation

    bool flag =false;
    for(auto it: adj)
        {
            if(d[it.u]+it.wt < d[it.v])
            {
                flag=true;
                cout<<" Negative Cycle Exists "<<endl;
                break;
            }
                
        }


    if(flag==false)
    {
        for(int i=0; i<n; i++)
            cout<<" Shortest distance from "<<src<< " to "<<i<< " is "<<d[i]<<endl;
    }
    return 0;
}