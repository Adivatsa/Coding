    void solve(vector<int> &c, int tar, int i, vector<int> op,
               vector<vector<int>> &ans )
    {
        
        //Base case
        //when it reaches to last index 
        if(i==c.size())
        {
            //check if target is equal to 0 then store the vector in ans vector
            //otherwise simply return;
            if(tar==0)
            {
                ans.push_back(op);
                return;
            }
            return;
        }
        
        //without including the index    
        //increase index and simply make recursion call
        solve(c,tar,i+1,op,ans);
        
        //Check if target should be less than or equal current integer
        if(c[i]<=tar)
        {
            //push into output vector and decrement target cvalue and make recursion call
            //we can use multiple times so do not increase index
            //while coming bac remove from output string
            //put the index elemnt to output string
            vector<int> op2=op;
            op2.push_back(c[i]);
            //decrementing the target
            tar= tar-c[i];
            //recursive call with incluing
            solve(c,tar,i,op2,ans);
            //op.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> op;
        //Starting index for iterating
        solve(candidates,target,0,op,ans);
        return ans;
    }