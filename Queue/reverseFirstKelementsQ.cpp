// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    //for reverse take stack it will reverse automatically 
    //put k elements into stack and then put into queue
    //at last for n-k elemets pop from front and push it back
    stack<int>s;
    for(int i=0; i<k; i++)
    {
        int element=q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty())
    {
        int element=s.top();
        s.pop();
        q.push(element);
    }
    
    for(int i=0; i<q.size()-k; i++)
    {
        int element=q.front();
        q.pop();
        q.push(element);
    }
    return  q;
}