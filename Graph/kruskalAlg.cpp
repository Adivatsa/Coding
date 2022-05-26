#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<algorithm>



using namespace std;
vector<pair<int,int>> p;//{parent, rank}
struct node{
    int u;
    int v;
    int wt;

    node(int a, int b, int weigt)
    {
        u=a;
        v=b;
        wt=weigt;
    }

};

int find(int node)
{
    if(p[node].first==-1)
        return node;
    return p[node].first=find(p[node].first);//path compresssion 
}

void callunion(int a , int b)
{
    //jiksa bhi rank jyada hga usme connect maar do
    int n1=find(a);
    int n2=find(b);

    if(p[n1].second>p[n2].second)
        p[n1].first=n2;
    else if(p[n1].second<p[n2].second)
        p[n2].first=n1;
    else
    {
        p[n1].first=n2;
        p[n2].second++;
    }
}

//comparator
bool comparator(node g, node f)
{
    return g.wt < f.wt;
}
    

int main()
{

    int n,e;
    cout<<" Enter the number of Nodes "<<endl;
    cin>>n;
    cout<<" Enter the numer of edges "<<endl;
    cin>>e;

    p.resize(n,{-1,0});//{parent, rank}

    vector<node> adj;
    for(int i=0; i<e; i++)
    {
        int m,n,wtt;
        cin>>m>>n>>wtt;
        adj.push_back(node(m,n,wtt));
        adj.push_back(node(n,m,wtt));
    }

    //sort them according to weight
    sort(adj.begin(), adj.end(),comparator);

    //Apply Disjoint set concept
    //to store it has been processed use one vector with u and v
    vector<pair<int,int>>vis;

    int cost=0;//calculation of cost
    for(auto it: adj)
    {
        if(find(it.u)!=find(it.v))//agar parent equal nai hai toh add kar do
        {
            callunion(it.u,it.v);//Union kar do dono set ka
            //cost ko add kar do
            cost+=it.wt;
            //it has been processed then add to visted
            vis.push_back({it.u,it.v});

        }
    }

    cout<<cost<<endl;

    for(auto it: vis)
        cout<<it.first<<"--"<<it.second<<endl;
    return 0;

}



//Using Striver Method

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<algorithm>



using namespace std;

struct node{
    int u;
    int v;
    int wt;

    node(int a, int b, int weigt)
    {
        u=a;
        v=b;
        wt=weigt;
    }

};

int find(int node, vector<int>& parent)
{
    if(node==parent[node])
        return node;
    return parent[node]=find(parent[node],parent);//path compresssion 
}

void callunion(int a , int b, vector<int>& parent, vector<int>& rank)
{
    //jiksa bhi rank jyada hga usme connect maar do
    int n1=find(a,parent);
    int n2=find(b,parent);

    if(rank[n1]>rank[n2])
        parent[n2]=n1;
    else if(rank[n1]<rank[n2])
        parent[n2]=n2;
    else
    {
        parent[n1]=n2;
        rank[n2]++;
    }
}

//comparator
bool comparator(node g, node f)
{
    return g.wt < f.wt;
}
    

int main()
{

    int n,e;
    cout<<" Enter the number of Nodes "<<endl;
    cin>>n;
    cout<<" Enter the numer of edges "<<endl;
    cin>>e;
    vector<node> adj;
    for(int i=0; i<e; i++)
    {
        int m,n,wtt;
        cin>>m>>n>>wtt;
        adj.push_back(node(m,n,wtt));
        adj.push_back(node(n,m,wtt));

    }
    vector<int> parent(n);
    for(int i=0; i<n; i++)
        parent[i]=i;
    vector<int> rank(n,0);
    //sort them according to weight
    sort(adj.begin(), adj.end(),comparator);

    //Apply Disjoint set concept
    //to store it has been processed use one vector with u and v
    vector<pair<int,int>>vis;

    int cost=0;//calculation of cost
    for(auto it: adj)
    {
        if(find(it.u,parent)!=find(it.v,parent))//agar parent equal nai hai toh add kar do
        {
            callunion(it.u,it.v,parent,rank);//Union kar do dono set ka
            //cost ko add kar do
            cost+=it.wt;
            //it has been processed then add to visted
            vis.push_back({it.u,it.v});

        }
    }

    cout<<cost<<endl;

    for(auto it: vis)
        cout<<it.first<<"--"<<it.second<<endl;
    return 0;

}