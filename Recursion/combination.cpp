    void solve(int index, int n, int k, vector<vector<int>>&res, vector<int> &op)
    {
        //Base Case
        //when size reaches to equal to k then push to resultant vector and return
        if(op.size()==k)
        {
            res.push_back(op);
            return;
        }
        
        //iterate over index till n
        for(int i=index; i<=n; i++)
        {
            op.push_back(i); //push into temporary vector and call to next index
            solve(i+1, n, k, res, op);
            op.pop_back(); //Backtracking
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> op;
        solve(1,n,k,res,op);
        return res;   
    }