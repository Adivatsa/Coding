    int findPeakElement(vector<int>& nums) {
        
        //Steps:
        
        //Apply binary search as it ahs been given that no two elements will be nums[i]==nums[i+1]
        
        //Apply Binary search and compare mid and mid+1 then incremnet s,e pointer
        int s=0;
        int e=nums.size()-1;
        int n=nums.size();
        if(n==1)
            return 0;
        
        int mid= s+ (e-s)/2;
        while(s<e)
        { 
            if(nums[mid]<nums[mid+1])
                s=mid+1;
            else
                e=mid;
            mid= s+ (e-s)/2;
        }
        return s;
        
    }