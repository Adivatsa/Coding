   int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0; i<n; i++)
            s.push(i);
        
        while(s.size()> 1)
        {
            
            int a= s.top();
            s.pop();
            int b= s.top();
            s.pop();
            
            if(M[a][b]==1)
                s.push(b);
            else
                s.push(a);
                
            
        }
        
        int potentialCeleb= s.top();
        
        int zeroCount=0;
        
        for(int i=0; i<n ;i++)
           if(M[potentialCeleb][i]==0) 
                zeroCount++;
        
        int oneCount=0;
        
        for(int i=0; i<n ;i++)
           if(M[i][potentialCeleb]==1) 
                oneCount++;
        
        if((zeroCount!= n)  || (oneCount!=(n-1)))
            return -1;
        
        
        return potentialCeleb;
    }