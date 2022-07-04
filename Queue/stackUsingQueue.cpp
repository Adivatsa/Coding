class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
        for(int i=0; i<q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        
        if(q.empty())
            return -1;
        int val=q.front();
        q.pop();
        return val;
        
    }
    
    int top() {
        if(q.empty())
            return -1;
        else
            return q.front();
        
    }
    
    bool empty() {
        if(q.empty())
            return true;
        else
            return false;
        
    }
};



void QueueStack :: push(int x)
{
        /*
        //Using Two Queue
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        */
        
        //Using Single queue
        q1.push(x);
        for(int i=0; i<q1.size()-1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        if(q1.empty())
        return -1;
        int val=q1.front();
        q1.pop();
        return val;
}