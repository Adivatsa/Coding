#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
void insertintoStack(stack<int>&s, int ele)
{
    if(s.empty() || s.top()<=ele)
    {
        s.push(ele);
        return;
    }
    int temp=s.top();
    //cout<<temp<<endl;
    s.pop();
    insertintoStack(s,ele);
    s.push(temp);
    return;
}

void sortstack(stack<int>&s)
{
    if(s.size()==1)
    {
        //cout<<" I am empty"<<endl;
        return;
    }

    int ele=s.top();
    //cout<<ele<<endl;
    s.pop();
    sortstack(s);
    insertintoStack(s,ele);
    return;
}

int main()
{

    stack<int> s;
    s.push(8);
    s.push(2);
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(6);
    //cout<<s.top()<<endl;
    sortstack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;

}