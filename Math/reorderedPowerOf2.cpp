    bool reorderedPowerOf2(int n) {
        
        //Main logic 
        //we have to find if any permutation of given number is power of two or not
        //if yes then return true else false
        //store the digit occurance count and itertate for power of 2 and compare then return 
        vector<int> v1(10,0);
        while(n)
        {
            int rem=n%10;
            v1[rem]++;
            n=n/10;
        }


        for(int i=1; i<=1000000000; i=i*2)
        {
            vector<int> v2(10,0);
            int num=i;
            while(num)
            {
                int rem=num%10;
                v2[rem]++;
                num=num/10;
            }

            if(v1==v2)
                return true;
        }
        return false;
        
    }