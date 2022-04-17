int knapSack(int N, int W, int val[], int wt[])
    {
        // In unbounded kanpsack an element can be taken more than one time
        //Similar to 0-1 kanpsack
        //If decision has been made to not include that element means it has been processed as decision final
        //But if something has been taken it means un future can be taken or not taken so decision not final so unprocessed
        //code similar to 0-1 kanpsack
        
        int t[N+1][W+1];
        
        for(int i=0; i<N+1; i++)
        {
            for(int j=0; j<W+1; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1; i<N+1; i++)
        {
            for(int j=1; j<W+1; j++)
            {
                if(wt[i-1] <= j)
                    t[i][j]=max(val[i-1]+t[i][j-wt[i-1]] , t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
       return t[N][W]; 
    }