    //Binary exponentiation function
    
    double powe(double x, int n)
    {
        if(n==0)
            return 1;
        double ans=powe(x,n/2);
        if(n&1)
        {
            return (x*ans*ans);
        }
        else
            return (ans*ans);
    }
    double myPow(double x, int n) {
        
        double res=0;
        int m;
        if(n<0)
            m=abs(n);
        
        res=powe(x,m);

        //checking for negative number so ans=1\ans
       if(n<0) 
            res=(1/res); 
        return res;
    }