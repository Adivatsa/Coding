    int wiggleMaxLength(vector<int>& nums) {
        
        //In this question we have a form a wiggle subsequence 
        //wiggle means increasing then decreasing or decreasing then increasing sequence when subtarcts the two consecutive snumber 
        //if for increasing sequence in the next term it is again inc then it will not be considered it will be redudnant as we don not require them
        //we have to retun max length of inc or desc subsequenece
        
        //At start we can consider one element as inc or desc so take thier count as 1
        //for increasing a[i]<a[i+1] and desc a[i]>a[i+1] and equal will have no effect so don nt update inc and desc 
        //for inc incremnet one more than desc(previous) and for desc update 1+ inc(previous)
        
        //Base case for single element max length wiggle subsequence are
        if(nums.size()==1)
            return 1;
        int inc=1;
        int desc=1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>nums[i-1])//increasing sequence
                inc=desc+1;
            else if(nums[i]<nums[i-1])//decresing sequence
                desc=inc+1;
        }
        //we want longest wiggle subsequence
        return max(inc,desc);
        
    }