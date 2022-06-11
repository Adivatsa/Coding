#include<iostream>

using namespace std;
bool lsearch(int arr[],int size,int key){

    for(int i=0;i<size;i++){
        if(arr[i]==key)
            return 1;
    }
    return 0;
}

int main(){

   
    int size;
    cout<<" Input the size of an array "<<endl;
    cin>>size;

    int a[100];
    cout<<" Input ur array of Size "<<size<<endl;
    for(int i=0;i<size;i++)
         cin>>a[i];
    int Key;
    cout<<" Enter the key "<<endl;
    cin>>Key;
    if(lsearch(a,size,Key))
        cout<<" Key is present"<<endl;
    else
        cout<<" Key is not present"<<endl;
    
    return 0;

}