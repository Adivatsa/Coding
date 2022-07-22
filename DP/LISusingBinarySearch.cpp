    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();

        
        //Using Binary Search
        //Take one temperoray vector
        //Traverse the array  and if greater than last element then push it
        //otherwise rewrite to next graeter element using lower bound function
        //it will behave like binary search
        
        //TC= o(nlong) Sc=O(n)
        vector<int> temp;
        int len=1;
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++)
        {
            if(nums[i]> temp.back())//it is greater than largest element in vector
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
               //use lower bound to find same element or just next greater element a
                //and Replace it
                
                int index=lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[index]=nums[i];
            }
        }
        return len;   
    }