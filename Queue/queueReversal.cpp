//Function to reverse the queue.
void reverseQueue(queue<int> &q)
{
    if(q.empty())
        return ;
    int data= q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);
}
queue<int> rev(queue<int> q)
{
    /*
    // Using Stack
    stack<int> s;
    
    while(!q.empty())
    {
        int data= q.front();
        q.pop();
        s.push(data);
    }
    while(!s.empty())
    {
        int data= s.top();
        s.pop();
        q.push(data);
    }
    return q;
    */
    
    //Using Recursion
    reverseQueue(q);
    return q;
    
}