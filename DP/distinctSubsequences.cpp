    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        //if all the strings of t ahs been taken
        if(j<0)
            return 1;
        //string s has been exhausted
        if(i<0)
            return 0;
         //Memoization
        if(dp[i][j]!=-1)
            return dp[i][j];
        //if it has been matched then it cam be taken or not taken 
        if(s[i]==t[j])
            return dp[i][j]=solve(s,t,i-1, j-1,dp) + solve(s,t, i-1, j,dp);
        else//if not matched
            return dp[i][j]=solve(s,t,i-1, j,dp);
        
    }
    int numDistinct(string s, string t) {
        
        //In this we have to found the for t string how many distinct subsequences are 
        //present inside the string s
        //Recursion
        //TC=)(2^m+ 2^n) SC=O(m+n)
        int n=s.length();
        int m=t.length();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return solve(s, t, n-1, m-1,dp);
        
        //Taulation Approach
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int> (m+1, 0));
        
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;   
            }
        }
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
       return (int)dp[n][m]; 
        
    }