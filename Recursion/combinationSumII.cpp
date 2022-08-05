void solve(vector<int> &c, int tar, int index, vector<int> &op,
               vector<vector<int>> &t )
        {
        
        //Base case
        //check if target is equal to 0 then store the vector in ans vector
        //otherwise simply return;
        if(tar==0)
        {
            t.push_back(op);
            return;
        }
        
        for(int i=index; i<c.size(); i++)
        {
            //check if it same as last element and if it has occured first time then we have to pick it 
            if(i>index && c[i]==c[i-1])
                continue;
            //if at any time found that element is greater than target than no way to reach target
            if(c[i]>tar)
                break;
            //push into temp vector
            op.push_back(c[i]);
            //function call
            solve(c,tar-c[i],i+1,op,t);
            //backtracking
            op.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> v;
        vector<int> op;

        solve(candidates,target,0,op,v);

        return v;
        
    }