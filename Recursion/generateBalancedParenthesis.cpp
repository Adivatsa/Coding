    void solve(int cnt,int c, string op, vector<string>&ans)
    {
        
        //jab dono ka count 0 ho jaaye means it is balanced paranthesis
        if(cnt==0 && c==0)
        {
            ans.push_back(op);
            return;
        }
        
        //starting we have only choice of open bracket
        //jab tak open hai toh hum use kar sakte hai
        if(cnt!=0)
        {
            //output string me open bracket daal do 
            //aur open ka count kam kar do
            //then call recursive function
            
            string op1=op;
            op1.push_back('(');
            solve(cnt-1,c,op1,ans);
            
        }
        if(c>cnt)
        {
            //it means closing jyada ho close bracket string me daal dnge and count kam kar denge
            string op2=op;
            op2.push_back(')');
            solve(cnt,c-1,op2,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        //hum log open and close bracket ka count rakhnege
        //jab tk open bracket ka count 0 nai hga we can insert open bracket
        //close bracket tb use karenge jab close bracket open se jyada hnge
        //iska matlb jyada open bracket already string me hnge
        //last me dono equal ho jaaye iska matlb hai ki balaced hai
        
        vector<string>ans;
        int cnt=n;//open bracket count
        int ccnt=n;//close bracket count;
        //output string
        string op;
        solve(cnt,ccnt,op,ans);
        return ans;
        
    }