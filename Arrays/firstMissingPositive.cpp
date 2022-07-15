    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0 && nums[i]<=n)
            {
                //find out the element and start checking from 1 to n
                //check if positive then it has been at thier correct location or not 
                //due to 0 indexing we are subtracting and comparing with integer+1
                //if not at correct position then swap and i-- so that it can check again from there
                int integer=nums[i]-1;
                if(nums[integer]!= integer+1) 
                {
                    swap(nums[integer], nums[i]);
                    i--;
                }
            }
            
        }
        
        //again iterating to check it which positive number is not present
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }