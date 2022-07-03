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


//Little optimised

int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack<int> s;
        //First push all into stack 
        for(int i=0; i<n; i++)
            s.push(i);
            
        //Jab tak one eemenrt not inside the stack
        while(s.size()>1)
        {
            //dono elements ko nekal lo check kar lo ek dhushre ko jannete hai ya nai
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(M[a][b]==1)
            {
                //in this case a knows b so a is not celebrity as celebrity should know no one
                s.push(b);
            }
            else
                s.push(a);
        }
        
        int ans=s.top();
        //once check if all row are zero and all column should be one excluding that element
        int zero=0;
        for(int i=0 ; i<n; i++)
        {
            if(M[ans][i]!=0)
                return -1;
            if(M[i][ans]!=1 && i!=ans)
                return -1;
        }
        return ans;
    }
