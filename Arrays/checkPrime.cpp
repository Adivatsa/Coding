#include<iostream>
using namespace std;
bool checkprime(int n)
{
    if(n==1)
        return false;
    
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(n%i==0)
            cnt++;
    }
    if(cnt==2)
        return true;

    return  false;

}
int main()
{
    int x;
    cout<<" Enter the Number to check is a prime or Not"<<endl;
    cin>>x;
    if(checkprime(x))
        cout<<" Given Number is a Prime Number "<<endl;
    else
        cout<<" Given Number is not a prime Number"<<endl;
    return 0;
}
