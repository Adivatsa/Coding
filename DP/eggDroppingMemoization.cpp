int t[101][10001];
    int solve(int k, int n)
    {
        //Base condition
        
        //when no of egg is 1 then in worst case go upto n floors
        if(k==1)
            return n;
        
        //if no of floors is 0 or 1 then then 0 and 1 attempts is required
        if(n==0 || n==1)
            return n;
        
        if(t[k][n]!=-1)
            return t[k][n];
        
        int mini=INT_MAX;
        //we have to find the thresold floor from 1 to n 
        for(int i=1; i<=n; i++)
        {
            //1 is added means one attempt used
            //max is for worst condition in which first case egg broked so go to down floor
            //otherwise go to up floor without breaking so no egg reduced
            int temp=1+max(solve(k-1,i-1), solve(k,n-i));
            
            //for minimum attempts
            mini=min(temp, mini);
        }
        
        return t[k][n]=mini;
        
    }
    int superEggDrop(int k, int n) {
        
        //here k is no of eggs and n is number of floors
        //we have to find out the threshold floor in minimum no of attempts
        //for the worst case we have to find out
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }


    //FURTHER OPTIMIZATION

    int t[101][10001];
    int solve(int k, int n)
    {
        //Base condition
        
        //when no of egg is 1 then in worst case go upto n floors
        if(k==1)
            return n;
        
        //if no of floors is 0 or 1 then then 0 and 1 attempts is required
        if(n==0 || n==1)
            return n;
        
        if(t[k][n]!=-1)
            return t[k][n];
        
        int mini=INT_MAX;
        //we have to find the thresold floor from 1 to n 
        for(int i=1; i<=n; i++)
        {
            //1 is added means one attempt used
            //max is for worst condition in which first case egg broked so go to down floor
            //otherwise go to up floor without breaking so no egg reduced
            int left,right,temp;
            if(t[k-1][i-1]!=-1)
                left=t[k-1][i-1];
            else
            {
                left=solve(k-1,i-1);
                t[k-1][i-1]=left;
            }
            
            if(t[k][n-i]!=-1)
                right=t[k][n-i];
            else
            {
                right=solve(k,n-i);
                t[k][n-i]=right;
            }
            temp=1+ max(left, right);
            
            //for minimum attempts
            mini=min(temp, mini);
        }
        
        return t[k][n]=mini;
        
    }
    int superEggDrop(int k, int n) {
        
        //here k is no of eggs and n is number of floors
        //we have to find out the threshold floor in minimum no of attempts
        //for the worst case we have to find out
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }


    //Passed on LEETCODE USING BINARY SEARCH
        int t[101][10001];
    int solve(int k, int n)
    {
        //Base condition
        
        //when no of egg is 1 then in worst case go upto n floors
        if(k==1)
            return n;
        
        //if no of floors is 0 or 1 then then 0 and 1 attempts is required
        if(n==0 || n==1)
            return n;
        
        if(t[k][n]!=-1)
            return t[k][n];
        
        int mini=INT_MAX;
        //we have to find the thresold floor from 1 to n 
        int l=1, e=n,temp;
        while(l<=e)
        {
            //1 is added means one attempt used
            //max is for worst condition in which first case egg broked so go to down floor
            //otherwise go to up floor without breaking so no egg reduced
            int mid= (l+e)/2;
            int left=solve(k-1,mid-1);
            int right=solve(k,n-mid);
            if(left<right)
            {
                l=mid+1;
            }
            else
                e=mid-1;
            temp=1+ max(left, right);
            
            //for minimum attempts
            mini=min(temp, mini);
        }
        
        return t[k][n]=mini;
        
    }
    int superEggDrop(int k, int n) {
        
        //here k is no of eggs and n is number of floors
        //we have to find out the threshold floor in minimum no of attempts
        //for the worst case we have to find out
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }