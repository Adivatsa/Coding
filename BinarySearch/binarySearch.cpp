#include<iostream>

using namespace std;
int binarySearch(int a[], int n, int key){

    int first=0;
    int last=n-1;
    int mid=first+ (last-first)/2;
    while(first<=last){

        if(a[mid]==key)
            return mid;
        if(a[mid]>key)
            last=mid-1;
        else
            first=mid+1;
        
        mid=first+(last-first)/2;
    }
    return -1;
}

int main(){

    int n;
    cout<<" Enter the Size of an array "<<endl;
    cin>>n;
    int a[10];
    cout<<" Enter the array "<<endl;
    for(int i=0; i<n;i++)
    {   
        int x;
        cin>>x;
        a[i]=x;
    }
    int key;
    cout<<" Enter the key to be searched "<<endl;
    cin>>key;
    int element = binarySearch(a,n,key);
    cout<<" Element is found at "<<element<<" position "<<endl;
    return 0;
}