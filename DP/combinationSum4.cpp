    int solve(vector<int>& nums, int t, vector<int>&dp)
    {
        //base case
        if(t<0)
            return 0;
        if(t==0)
            return 1;
        if(dp[t]!=-1)
            return dp[t];
        int ways=0;
        //start from 0 to all the elemts just check and return the ways
        for(int i=0; i<nums.size(); i++)
        {
            ways+=solve(nums, t-nums[i], dp);
        }
        return dp[t]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);   
    }