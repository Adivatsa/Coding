    void solve(vector<int>& nums, int index, set<vector<int>> &s)
    {
        //base case
        if(index==nums.size())
        {
            s.insert(nums);
            return ;
        }
        for(int i=index; i<nums.size(); i++)
        {
            //swap both the index
            swap(nums[i], nums[index]);
            solve(nums,index+1, s);
            //Backtrack
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;

        solve(nums, 0, s);
        
        vector<vector<int>> ans;
        for(auto it: s)
        {
                ans.push_back(it);
        }
        return ans;
        
        
    }