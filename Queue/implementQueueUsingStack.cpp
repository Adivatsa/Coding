    
    //TC=O(n)   SC=O(n)
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {
        if(s1.empty())
            return -1;
        int val=s1.top();
        s1.pop();
        return val;
        
    }
    
    int peek() {
        
        if(s1.empty())
            return -1;
        else
            return s1.top();    
    }
    
    bool empty() {
        
        if(s1.empty())
            return true;
        else
            return false;    
    }


    //TC=O(1) accomotised based on no of operation SC=O(n)
    //in worst case TC=O(n)

    stack<int> ip;
    stack<int> op;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        ip.push(x);   
    }
    
    int pop() {
        if(!op.empty())
        {
           int val=op.top();
            op.pop();
            return val;
        }
            
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
        int val=op.top();
        op.pop();
        return val;
        
    }
    
    int peek() {
        
        if(!op.empty())
            return op.top();
        else
        {
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        
        if(op.empty() &&ip.empty())
            return true;
        else
            return false;    
    }
