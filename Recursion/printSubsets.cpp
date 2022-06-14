void solve(vector<int> nums, vector<vector<int>>&ans, vector<int> &temp)
    {
        
        //base case
        //When input size will be 0
        if(nums.size()==0)
        {
            ans.push_back(temp);
            return;
        }
        
        //create two ouput vector where one will inlcude and other not
        vector<int> op1=temp;//do not include
        vector<int> op2=temp;//include it
       //for including push into vector 
        op2.push_back(nums[0]);
        //delete the first element from input vector
        nums.erase(nums.begin()+0);
        
        //recursive call for remaining elements with one as include and not include
        solve(nums,ans,op1);
        solve(nums,ans,op2);
    
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        //Answer vector to store and return all the subsets
        vector<vector<int>>ans;
        //This is temp for storing output
        vector<int> temp;
        solve(nums,ans, temp);
        return ans;
        
    }