#include<iostream>
#include<queue>

using namespace std;

//Step 1: Prepare Adjaceny list
//Step 2: make key, mcs,parent array with infinity, false, -1 respectively
//Step 3: In brute force we have process minimu among key first so it take O(n^2)
//Step 4: Use priority queue for key array
//Take any node mark in mcs as True and if distance to adjacent is less than update it and mark parent as node to adj node

int main()
{
    int v,e;
    cout<<" Enter the Number of Nodes "<<endl;
    cin>>v;
    cout<<" Enter the Number of edges "<<endl;
    cin>>e;

    //ip
    // 4 0 4
    // 4 3 9
    // 0 3 1
    // 0 1 2
    // 3 1 3
    // 3 2 5
    // 1 2 3
    // 1 5 7
    // 2 5 8

    //op
    // 0 - 1 --2
    // 1 - 2 --3
    // 0 - 3 --1
    // 0 - 4 --4
    // 1 - 5 --7
    vector<vector<pair<int,int>>> adj(v);

    for(int i=0; i<e; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }


    //Brute force approach for Prims
    //TC=O(n^2)
    vector<int> key(v,INT_MAX);
    vector<bool> mcs(v,false);
    vector<int> p(v,-1);

    key[0]=0;

    //iterate over total v-1 edges


    //optimised Approach use priority queue  TC=O(n^2)


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;


    //store in form of {key value , index}
    //chota jiska key value hga ushe nekalna hai so isliye wo chahiye

    q.push({0,0});
    for(int c=0; c<v-1; c++)
    {
        // int mini=INT_MAX;
        // int node;

        // //FInd out the minimum in key array which is not included in mcs
        // for(int i=0; i<v; i++)
        // {
        //     if(mcs[i]==false && key[i]<mini)
        //     {
        //         mini=key[i];
        //         node=i;
        //     }
        // }

        int node=q.top().second;
        q.pop();

        //now the node has to be included so mark true and check adjacent nodes if weight less update it
        mcs[node]=true;

        for(auto it: adj[node])
        {
            int nextnode=it.first;
            int newwt=it.second;

            //if not has been included in mcs and weight is less than update it
            if(mcs[nextnode]==false && key[nextnode]>newwt)
            {
                key[nextnode]=newwt;
                p[nextnode]=node;
                q.push({newwt,nextnode});//extra line with p queue
            }
        }


    }
    //printing minimum spanning treee
    for(int i=1; i<v; i++)
        cout<<p[i]<<" - "<<i<<" --"<<key[i]<<endl;
}