    vector<int> twoSum(vector<int>& nums, int target) {
        
        //create a map to store key and value as position
        unordered_map<int,int>m;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            //if target - element is present in map then push it vector otherwise store in map
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;//each input only one solution accoeding to question
            }
            m[nums[i]]=i;
        }
        return ans;
        
    }