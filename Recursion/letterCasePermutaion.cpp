void solve(string s, string op, vector<string> &ans)
    {
        //Base case
        if(s.length()==0)
        {
            ans.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
         char ch=s[0];
        //Check if it is a letter as 9 has asci value 57
        if(ch>57)
        {
            //Two choices with one convert and other do not convert
            if(ch>=65 && ch<=90)//A=65 Z=90 a=97 z=122
            op2.push_back(ch+32);//convert to lowercase
        else
            op2.push_back(ch-32);
            
        //Do not convert 
        op1.push_back(ch);
        
        //Erase from input string
        s.erase(s.begin()+0);
        //Recursive calls
        solve(s,op1,ans);
        solve(s,op2,ans);
        }
        else//if numbers then simply copy delete from input string and call recursion 
        {
            op1.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,op1,ans);
        }
            
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;
        
        string op;
        solve(s,op,ans);
        return ans;
        
    }