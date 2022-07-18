    int lastStoneWeight(vector<int>& stones) {
        
        //Create the max heap and insert all elements into heap
        priority_queue<int> maxheap;
        for(int i=0; i<stones.size(); i++)
            maxheap.push(stones[i]);
        
        //till queue size greater than 1 
        //pop top two elements and according to condition if both equal then pop both 
        //otherwise push greater - smaller into max heap
        while(maxheap.size()>1)
        {
            int y=maxheap.top();
            maxheap.pop();
            int x=maxheap.top();
            maxheap.pop();
            
            if(x==y)
            {
               
                cout<<x<<" "<<y<<endl;
                continue;
            }
                
            else if(y>x)
                maxheap.push(y-x);
                
        }
        if(maxheap.empty())
            return 0;
        else
            return maxheap.top();
        
    }