    void solve(string digits, string map[], string op, int index, vector<string>&ans)
    {
        
        //base case when index greater than digits list
        if(index>=digits.size())
        {
            //op wala string lo ans string me daal ke return ho jao
            ans.push_back(op);
            return;
        }
        
        //Take the number
        int number=digits[index]-'0';//digits will ahve char type so subtarct 0 to get num
        //getting the mapping string
        string temp=map[number];
        
        for(int i=0; i<temp.length(); i++)
        {
            //Put into output string and call recursion and while coming back pop it
            op.push_back(temp[i]);
            solve(digits,map,op,index+1,ans);
            op.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        
        string op;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        solve(digits,map,op,index,ans);
        return ans;
        
    }