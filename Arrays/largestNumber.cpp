string largestNumber(vector<int>& nums) {
        
        //iterate over the nums array and sort them according to two pointer 
        //form a string with i and j pointer and in descending order
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                string s1=to_string(nums[i])+ to_string(nums[j]);
                string s2=to_string(nums[j])+ to_string(nums[i]);
                if(s1<s2)
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
        string ans;
        for(int i=0; i<nums.size(); i++)
            ans=ans+to_string(nums[i]);
        //check if all are 0's then  take a single 0 and return it
        if(ans[0]=='0')
            return "0";
        else    
            return ans;
    }