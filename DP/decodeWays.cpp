    int solve(string s, int i, vector<int> &t)
    {
        //base case
        if(i==s.length())
            return 1;
        if(s[i]=='0')
            return 0;
        if(i==s.length()-1)
            return 1;
        if(t[i]!=-1)
            return t[i];
        string ss=s.substr(i,2);
        int first= solve(s,i+1,t);
        int second=0;
        if(stoi(ss)>0 && stoi(ss)<=26)
            second=solve(s,i+2,t);
        return t[i]= first+ second;
    }
    int numDecodings(string s) {
        
        int n=s.length();
        //vector<int> t(n,-1);
        //return solve(s,0,t);
        
    }