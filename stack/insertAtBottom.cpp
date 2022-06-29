void enterlast(stack<int>& s, int x)
{
    //Base  condition
    if(s.empty())
    {
        s.push(x);
        return ;
    }
    int ele= s.top();
    s.pop();
    enterlast(s,x);
    s.push(ele);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    enterlast(myStack, x);
    return myStack;
}