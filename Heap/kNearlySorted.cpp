#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

void knearlysorted(int arr[], int n, int k, vector<int> &ans)
{
    priority_queue<int, vector<int> , greater<int>>m;
    for(int i=0; i<n; i++)
    {
        m.push(arr[i]);
        if(m.size()>k)
        {
            ans.push_back(m.top());
            m.pop();
        }
    }
    while(!m.empty())
    {
        ans.push_back(m.top());
        m.pop();
    }
    
    
}

int main()
{
    int n;
    cout<<" Enter the Size of an array "<<endl;
    cin>>n;
    int arr[100];
    cout<<" Enter the Elements in an array"<<endl;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }

    vector<int> ans;
    int k;
    cout<<" Enter the value of K "<<endl;
    cin>>k;
    knearlysorted(arr,n,k,ans);

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
}