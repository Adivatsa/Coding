void deleteMid(stack<int>&s, int sizeOfStack)
    {
        //Extra space we don't have to consume
        //so take out elemnet and call recursively
        //check for base condition when size of stack +1 /2 then delete and return
        //while returning add all the elements abck to stack
        if(s.size()==((sizeOfStack+1)/2))
        {
            s.pop();
            return;
        }
        
        int ele=s.top();
        s.pop();
        deleteMid(s,sizeOfStack);
        s.push(ele);
    }