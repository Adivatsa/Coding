    int countPrimes(int n) {
        
        //Steps:
        //Apply Sieve of Eratosthenes
        //Create a vector of size with all as true
        //iterate over the array and mark multiples of 2,3,4,... to false
        //At last count which has  true and return the count
        //Tc= O(n* log(logn))
        vector<int> v(n,1);
        if(n<2)
            return 0;
        v[0]=v[1]=0;
        //itearte from 2 to sqrt(n) as after that it will repeated in reverse order
        for(int i=2; i*i<n; i++)
        {
            if(v[i]==true)//if it is true then mark it as false
            {
                for(int j=i*i; j<n; j+=i)//before i*i it has been already marked by someone
                {
                    v[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(v[i]==true)
                cnt++;
        }
        return cnt; 
    }s