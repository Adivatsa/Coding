    int mirrorReflection(int p, int q) {
        //based upon the formuale for finding m*p=n*q where
        // m is no of room +1 and n is no of reflection +1
        while(p%2==0 &&q%2==0)
        {
            p=p/2;
            q=q/2;
        }
        //p even q odd = 2
        if(p%2==0 && q%2!=0)
            return 2;
        //p is odd and q is even =0
        if(p%2!=0 && q%2==0)
            return 0;
        //p is odd and q is odd =1
        if(p%2!=0 && q%2!=0)
            return 1;
        return -1;
    }