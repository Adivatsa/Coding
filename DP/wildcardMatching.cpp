    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &t)
    {
        //Base Case
        //Both the strings has been finished
        if(i<0 && j<0)
            return true;
        
        //when 1st has been finished while second is remaining
        if(i<0 && j>=0)
            return false;
        
        //when 1st is remaing and second has been finished then check for * character
        if(j<0 && i>=0 )
        {
            for(int k=0; k<=i; k++)
            {
                if(s[k]!='*')
                    return false;
            }
            return true;
        }
        
        //Memoization Step
        if(t[i][j]!=-1)
            return t[i][j];
        
        
        //if matching or ? character in first string then they matched
        if((s[i]==p[j]) ||(s[i]=='?'))
            return t[i][j]=solve(i-1, j-1, s,p,t);
        
        //Check when * charaters then check for take 0 charactern or not take character
        if(s[i]=='*')
            return t[i][j]=solve(i-1,j,s,p,t) || solve(i,j-1,s,p,t);
        //it means not has been matched and no ?,* character
        return t[i][j]=false;
    }
    bool isMatch(string s, string p) {
        
        //Recursion Approach
        
        //Here p string has a-z, ?,* and s has only a-z
        int n=s.length();
        int m=p.length();
        
        //Memoization
        // vector<vector<int>> t(m, vector<int> (n,-1));
        // return solve(m-1, n-1, p, s,t);
        
        //Tabulation Approach
        vector<vector<bool>> t(m+1, vector<bool> (n+1, false));
        //fill the first column
        for(int i=1; i<m+1; i++)
        {
            bool flag=true;
            for(int k=1; k<=i; k++)
            {
                if(p[k-1]!='*')
                {
                    flag= false;
                    break;
                }   
            }
            t[i][0]=flag;
        }
                
        t[0][0]=true;
        
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if((p[i-1]==s[j-1]) ||(p[i-1]=='?'))
                    t[i][j]=t[i-1][j-1];
                else if(p[i-1]=='*')
                    t[i][j]=t[i-1][j]|| t[i][j-1];
                else
                    t[i][j]=false;
            }
        }
        return t[m][n];
    }