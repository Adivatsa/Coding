V    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=1)
            return 0;
            
        //Start will be start of subarray with same  difference
        int s=0, e=1;
        int res=0;
        int diff=0;
        
        for(int i=1; i<n-1; i++)
        {
            //difference to be maintained
            diff=nums[e]- nums[s];
            while(i+1<n && (nums[i+1]- nums[i]==diff) )
            {
                i++;
                e++;
            }
            //length of subaary with same difference
            int len=(e-s)+1;
            if(len>=3)//At each time 3 is counted as 1 then 2 .... so n is replaced by n-2 
                res+=((len-2)* (len-2+1))/2;
            //start will start from end and end will be one greater
            s=e;
            e++;
        }
        return res;
    }