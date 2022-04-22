    
    int t[1001][1001];
    
 /* //Bottom up approach Passed
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        
        //Intialization step
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if(i==0 || j==0)//first row and column
                    t[i][j]=0;
            }
        }
      
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(S1[i-1] == S2[j-1])//last letter matched increase count by 1 and call for other remaining string
             t[i][j]=1+ t[i-1][j-1];
        else
             t[i][j]=max(t[i-1][j] , t[i][j-1]);
            }
        }

      return t[n][m];  
    }
*/ 
    //Memoization all test case passed
    int longestCommonSubstr(string &S1, string &S2, int n, int m)
    {
        
        
        //Base condition(tink of smallest valid input)
        if(n==0 || m==0)
            return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(S1[n-1] == S2[m-1])//last letter matched increase count by 1 and call for other remaining string
            return t[n][m]=1+longestCommonSubstr(S1, S2, n-1, m-1);
        else
            return t[n][m]=max(longestCommonSubstr(S1, S2, n-1, m) , longestCommonSubstr(S1, S2, n, m-1));
    }
    
    /*//Recursion gives TLE
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        
        
        //Base condition(tink of smallest valid input)
        if(n==0 || m==0)
            return 0;
        
        if(S1[n-1] == S2[m-1])//last letter matched increase count by 1 and call for other remaining string
            return 1+ longestCommonSubstr(S1, S2, n-1, m-1);
        else
            return max(longestCommonSubstr(S1, S2, n-1, m) , longestCommonSubstr(S1, S2, n, m-1));
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        
        // Method 1: Recursive approach
       // return longestCommonSubstr(text1, text2, text1.length(), text2.length());
        
        //Method 2: Memoization(recursion with table)
        memset(t, -1, sizeof(t));
        return longestCommonSubstr(text1, text2, text1.length(), text2.length());
        
        //Method 3: Tabulation Bottom up approach
        
        
        
        //return longestCommonSubstr(text1, text2, text1.length(), text2.length());
        
    }