#include<iostream>
#include<stack>

using namespace std;
void delmiddle(stack<int> &s, int k)
{
    //base case
    if(s.size()==k)
    {
        s.pop();
        return;
    }

    int ele=s.top();
    s.pop();
    delmiddle(s,k);
    s.push(ele);
}
int main()
{
    stack<int> s;
    //s.push(8);
    s.push(2);
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(6);
    int mid=s.size()/2 +1;
    delmiddle(s,mid);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}