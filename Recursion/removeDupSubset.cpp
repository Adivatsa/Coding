    void solve(vector<int> nums,vector<int>op, set<vector<int>>&s)
    {

        //Base case 
        //When input string is empty put in the set to remove duplicates
        if(nums.size()==0)
        {
            s.insert(op);
            return;
        }
        
        //Recurisive Tree method to include or not include
        vector<int>op1=op;
        vector<int>op2=op;
        
        //including
        op2.push_back(nums[0]);
        
        //Removing first element from input string
        nums.erase(nums.begin()+0);
        
        //Recursive Calls
        solve(nums,op1,s);
        solve(nums,op2,s);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        //sort to decrease the duplicay with {4,1}and{1,4} inside subset are same
        sort(nums.begin(), nums.end());
        //Using set to eliminate duplicacy of subsets
        set<vector<int>> s;
        vector<int> op;
        
        solve(nums,op,s);
        
        //Copy from set to vector
        vector<vector<int>>ans;
        for(auto it: s)
            ans.push_back(it);
        
        return ans;
        
    }