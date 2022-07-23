    int findNumberOfLIS(vector<int>& nums) {
       
        //Everything is same as LIS and just take one count array 
        //if same length of LIS is found then add to previous otherwise just copy previous
        int n=nums.size();
        vector<int> t(n,1);
        vector<int> cnt(n,1);
        int maxi=1;

        for(int index=0; index<n; index++)
        {
            for(int pindex=0; pindex<index; pindex++)
            {
                if(nums[index]> nums[pindex] && (1+ t[pindex]> t[index]))
                   {
                       t[index]= 1 + t[pindex];
                        cnt[index]=cnt[pindex];//just copy when greater 
                   }
                else if(nums[index]> nums[pindex] && (1+ t[pindex]== t[index]))
                {
                    //It means same as earlier then  just add in count array
                    cnt[index]+=cnt[pindex];
                }
            }
            if(t[index]>maxi)
            {
                maxi=t[index];
            }
        }
        
        //Sum all the count having length as maxi
        int len=0;
        for(int i=0; i<n; i++)
        {
            if(t[i]==maxi)//sum all the count having LIS length as maxi
                len+=cnt[i];
        }
        return len;
    }