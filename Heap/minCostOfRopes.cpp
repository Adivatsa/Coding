long long minCost(long long arr[], long long n) {
        
        //isme do least cost ko add karna hai 
        //min heap will have already least cost at top
        //jab tk heap ka size greater than 2 tab tk karna hai
        //isme hum dono ko add karne ke baad ushe bhi heap me push kar denge
        //cost will be added at each iteration
        long long ans=0;
        
        priority_queue<long long,vector<long long >, greater<long long>> q;
        for(int i=0; i<n; i++)
        {
            q.push(arr[i]);
            
        }
        
        while(q.size()>1)
        {
            long long x=q.top();
            q.pop();
            long long y=q.top();
            q.pop();
            ans+=x+y;
            q.push(x+y);
        }
        return ans;
    }