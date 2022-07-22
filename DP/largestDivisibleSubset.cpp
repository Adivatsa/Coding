    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> t(n, 1);
        //Track will store which ahs been last added for lis index
        vector<int> track(n,0);
        //used for backtarcking
        int startIndex=0;
        //finding the max length LIS
        int maxi=0;
        for(int index=0 ; index<n; index++)
        {
            track[index]=index;
            for(int pindex=0; pindex<index; pindex++)
            {
                if((nums[index] % nums[pindex]==0) && t[pindex]+1 > t[index])
                {
                    t[index]=t[pindex]+1;
                    //updation on track vector
                    track[index]=pindex;
                }
                    
            }
            if(t[index]>maxi)
            {
                maxi=t[index];
                startIndex=index;
            }
        }
        for(auto it: track)
            cout<<it<<endl;
       
        
        vector<int> print;
        print.push_back(nums[startIndex]);
        //Backtrack and print the LIS
        while(track[startIndex]!=startIndex)
        {
            startIndex=track[startIndex];
            print.push_back(nums[startIndex]);
        }
        reverse(print.begin(), print.end());
        return print;
    }