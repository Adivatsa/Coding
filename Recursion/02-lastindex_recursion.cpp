#include<iostream>
#include<array>

using namespace std;

int lastindex(int *arr, int startindex, int key,int size)
{
    //Base case
    //jab pura he element search karke last se bahr chala jaaye toh -1 return maar do 
    
    if(startindex==size)//agar index array se bahr chala jaaaye
        return -1;

    
    //recursion call marr do
    int index=lastindex(arr, startindex+1,key,size);//ye check karega next index se last tk 

    //waha se index ya toh -1 aayega matlab nai mila
    //ya index aayega last wala

    //agar -1 hai toh check kar lo sabse first wale index se matlb 0th se agr mila toh 0 index hga warna -1 hga
    if(index==-1)
    {
        if(arr[startindex]==key)
            return startindex; //matlb sabse first index pe key mil gya
        else
            return -1;//nai mil paaya key
    }
    else
        return index;//already mila hua hai
}

int main()
{
    
    int arr[6]={2,4,5,2,6,2};
    int key=2;
    int n=(sizeof(arr)/sizeof(arr[0]));
    int index=lastindex(arr,0,key,n);
    cout<<" Last index of "<<key <<" is "<<index<<endl;
    return 0;

}