#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
// 	pair<int, int> p;
    
//     unordered_map<int,int> m;
//     for(int i=0; i<n ; i++)
//     {
//         m[arr[i]]++;
//         if(m[arr[i]]>1)
//             p.second=arr[i];
//     }
    
//     for(int i=1; i<=n; i++)
//     {
//         if(m[i]==0)
//         {
//            p.first=i;
//             break; 
//         }    
//     }
//     return p;
    
    
    //2nd method using sum and sum of square method
    pair<int,int> pa;

    int s=(n*(n+1))/2;
    int p=(n*(n+1)*(2*n+1))/6;
    for(int i=0; i<n; i++)
    {
        s=s-arr[i];
        p=p-(arr[i]*arr[i]);
    }
    
    //x is missing number and y is duplicate number
    //x-y=s
    //x^2-y^2=ss
    
    int temp=((p/s)+s)/2;
    pa.second=(temp)-s;
    pa.first=temp;
    return pa;
}
