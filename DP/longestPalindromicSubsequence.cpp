int t[1001][1001];
    int longestPalinSubseq(string A) {
        
        //Find all subsequences , then find which are palindromic then largest among them
        //First step is to understand how it is similar to LCS problem
        //In this LPS only one string is given but LCS requires 2 Strings
        //for this u can find 2nd string as a function of first string using brain storming
        //So b= reverse of string a
        //Now u can apply LCS u can get LPS
       
       string b=A;
       reverse(A.begin(), A.end());
       int n=A.length();
       int m=b.length();

        for(int i=0; i<m+1; i++)
       {
           for(int j=0; j<n+1; j++)
           {
               if(i==0 || j==0)
                    t[i][j]=0;
           }
       }
       
       for(int i=1; i<m+1; i++)
       {
           for(int j=1; j<n+1; j++)
           {
               if(b[i-1]==A[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
           }
       }
        return t[m][n];
       
    }