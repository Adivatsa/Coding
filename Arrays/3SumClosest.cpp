    int threeSumClosest(vector<int>& nums, int target) {
        
        //STEPS:
        //Sort the array and fixed one and aplly two pointer approach
        //for closest maintain a variable for diff which will near to target 
        int diff=INT_MAX;
        sort(nums.begin() , nums.end());
        int n=nums.size();
        int ans=0;
        for(int k=0; k<n; k++)
        {
            
            int i=k+1;
            int j=n-1;
            while(i<j)
            {
                if((nums[k]+ nums[i]+ nums[j])==target)
                    return target;
                else if(abs(nums[k]+ nums[i]+ nums[j]-target)<diff)
                {
                    diff=abs(nums[k]+ nums[i]+ nums[j]-target);
                    ans=nums[k]+ nums[i]+ nums[j];
                }

                if((nums[k]+ nums[i]+ nums[j])>target)
                    j--;
                else
                    i++;   
            }  
        }
        return ans; 
    }