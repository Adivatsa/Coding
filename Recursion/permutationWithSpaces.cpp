    void solve(string s, string op, vector<string>&ans )
    {
        //if input string is empty then print the output string
        if(s.length()==0)
        {
            ans.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        
        //One with include space otherwithout space
        op1.push_back(' ');
        op1.push_back(s[0]);
        //Not including space
        op2.push_back(s[0]);
        //erasing the first element from input string
        s.erase(s.begin()+0);
        //recursive call
        solve(s,op1,ans);
        solve(s,op2,ans);
        
    }
    vector<string> permutation(string S){
        
        //We have to print all permuations with spaces
        //first and last space should be ignored
        //output string with first character intailly
        //then call recursion to add next chararcter with space or not space
        //A will be A_B or AB
        
        vector<string> ans;
        string op;
        //Push first element to output string
        op.push_back(S[0]);
        //Erase first element from input string
        S.erase(S.begin()+0);
        
        solve(S,op,ans);
        return ans;
    }