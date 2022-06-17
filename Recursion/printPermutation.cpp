
//TC=O(n!*n) Sc=O(1)
//GFG Solution

	    void solve(string &S, set<string>&s, int index)
	    {
	        //Base case
            if(index>=S.length())
	        {
	            s.insert(S);
	            return;
	        }
	        
	        for(int i=index; i<S.length(); i++)
	        {
    	        //First the indeces
    	        swap(S[index],S[i]);
    	        //Recursive Call
    	        solve(S,s,index+1);
    	        //We have changed into orignal String so change back while returning back
    	        swap(S[index],S[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    set<string> s;

		    solve(S,s,0);
		    
		    vector<string> ans;
            //To remove the dupliacy we have used SET data structure
		    for(auto it: s)
		        ans.push_back(it);
		    sort(ans.begin(), ans.end());
		    return ans;
		}


//Leetcode

    void solve(int index, vector<vector<int>> &ans, vector<int>& nums)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(index+1,ans,nums);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        solve(0,ans,nums);
        return ans;
        
    }