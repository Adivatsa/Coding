bool isSubsequence(string s, string t) {
        
//         //1st Approach: Using two pinter approach 
//         //just take two pointer in both the string and start comapring
//         //If u get the string then return T otherwise F
        
//         int m=s.length();
//         int n=t.length();
        
//         if(m==0 )
//             return true;
//         else if(n==0)
//             return false;
//         int i=0;
//         int j=0;
        
//         while(i<m && j<n)
//         {
//             if(s[i]==t[j])
//             {
//                 i++;
//                 j++;
//             }
//             else
//             {
//                 j++;
//             }
//         }
//         if(i==m)
//             return true;
//         else
//             return false;
        
        
        //2nd approach: Using DP
        //we know that it is asking for subsequence present in string t
        //If it is present thrn return true otherwise false
        //Main logic is use LCS and at last compare for length of given subsequnce
        //if we get desired length equal to our lcs then return true
        
        int m=s.length();
        int n=t.length();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<m+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        if(dp[m][n]==m)
            return true;
        return false;
        
    }