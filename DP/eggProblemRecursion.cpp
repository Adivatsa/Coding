int superEggDrop(int k, int n) {
        
        //here k is no of eggs and n is number of floors
        //we have to find out the threshold floor in minimum no of attempts
        //for the worst case we have to find out
        
        //Base condition
        
        //when no of egg is 1 then in worst case go upto n floors
        if(k==1)
            return n;
        
        //if no of floors is 0 or 1 then then 0 and 1 attempts is required
        if(n==0 || n==1)
            return n;
        
        int mini=INT_MAX;
        //we have to find the thresold floor from 1 to n 
        for(int i=1; i<=n; i++)
        {
            //1 is added means one attempt used
            //max is for worst condition in which first case egg broked so go to down floor
            //otherwise go to up floor without breaking so no egg reduced
            int temp=1+max(superEggDrop(k-1,i-1), superEggDrop(k,n-i));
            
            //for minimum attempts
            mini=min(temp, mini);
        }
        
        return mini;
        
    }