    int solve(int n, vector<int> &t)
    {
        if(n<3)
            return n;
        if(t[n]!=-1)
            return t[n];
        int ans=n;
        for(int i=1; i*i<=n; i++)
            ans=min(ans,1+ solve(n-i*i,t));
        return t[n]=ans;
    }
    int numSquares(int n) {
        //Steps:
        //we have to see only the perfect square if found then add +1 and call for next
        vector<int> t(n+1,-1);
        return solve(n,t);  
    }