    
    //Failed in Leetcode with integer overflow condition
    stack< long long int> s;
    long long int  mini=-1;
    MinStack() {
        
    }
    
    void push(int val) {
        //if stack is emoty simply push and assign it to min element
        if(s.empty())
        {
            mini=val;
            s.push(val);
        }
        else if(val>=mini)
            s.push(val);
        else
        {
            s.push(2*val-mini);
            mini=val;
        }
        
    }
    
    void pop() {
        
        //if empty the return -1 
        if(s.empty())
            s.pop();
        else
        {
            if(s.top()>mini)
                s.pop();
            else
            {
                mini=2*mini-s.top();
                s.pop();
            }
        }
        
    }
    
    int top() {
        
        if(s.empty())
            return -1;
        else
        {
            if(s.top()>mini)
                return s.top();
            else
                return mini;
            
        }
        
    }
    
    int getMin() {
        
        //When Stack is empty then return -1
        if(s.empty())
            return -1;
        else
            return mini;
    }



    //Accepted in Leetcode using two stack

        stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int val) {
        
        s.push(val);
        if(ss.empty() || val<=ss.top())
            ss.push(val);
        
    }
    
    void pop() {
        
        if(ss.empty())
            return;
        else
        {
            if(s.top()==ss.top())
                ss.pop();
            s.pop();
        }
        
    }
    
    int top() {
        if(s.empty())
            return -1;
        else
            return s.top();

    }
    
    int getMin() {
        if(ss.empty())
            return -1;
        else
            return ss.top();
        
    }