    int numTrees(int n) {
        
        //Catlan Number=1/(n+1) *(2nCn)
        
        //Another is cat(2)=cat(0)*cat(1) + cat(1)* cat(0)
        //cat[3]=c2*c0 + c1*c1 + c0*c2
        vector<int> cat(n+1,0);
        cat[0]=1;
        cat[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {

                cat[i]+= cat[j]* cat[i-j-1];
            }
        }
        return cat[n];
        
    }