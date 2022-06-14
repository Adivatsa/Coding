    void insertLast(stack<int> &s, int ele)
    {
        
        //base case
        if(s.empty())
        {
            //Empty ho jaaye toh push kar do
            s.push(ele);
            return;
        }
        
        int temp=s.top();
        s.pop();
        insertLast(s,ele);
        s.push(temp);
        return;
    }
    void reverseStack(stack<int> s)
    {
        //Base case
        if(s.size()==1)
            return;
            
        int ele=s.top();
        s.pop();
        reverseStack(s);
        insertLast(s,ele);
        return;
    }
    vector<int> Reverse(stack<int> St){
        
        //Reverse the stack without extra space
        
        vector<int> v;
        //Base case
        if(St.empty())
            return v;
        
        reverseStack(St);
        
        while(!St.empty())
        {
            v.push_back(St.top());
            St.pop();
        }
        return v;
    }