    int t[1001][1001];
    
    /*int LCSubstring(string S1, string S2, int n, int m, int &count)
    {
        //Base condition(tink of smallest valid input)
        if(n==0 || m==0)
            return 0;
        
        if(t[n][m]!=-1)
            return t[n][m];
        
        if(S1[n-1] == S2[m-1])//last letter matched increase count by 1 and call for other remaining string
             t[n][m]=LCSubstring(S1, S2, n-1, m-1,count+1);
        else
        {
            count=0;
            LCSubstring(S1, S2, n, m-1,count);
            LCSubstring(S1, S2, n-1, m,count);
            return count;
        }
        }
        */
    
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        
        //whenever matching broken down again start from zero longest common
        /*// Method 1: Recursive approach
        
        //Base condition(tink of smallest valid input)
        if(n==0 || m==0)
            return 0;
        
        if(S1[n-1] == S2[m-1])//last letter matched increase count by 1 and call for other remaining string
            return 1+ longestCommonSubstr(S1, S2, n-1, m-1);
        else
            return (longestCommonSubstr(S1, S2, n-1, m) , longestCommonSubstr(S1, S2, n, m-1));
        */
        /*//Method 2: Using Memoization(recursion with table)
        memset(t,-1,sizeof(t));
        int count=0;
        LCSubstring(S1,S2,n,m,0);
        return count;*/
        
        //Method 3: Bottom up approach
        
        //Intailization
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        
        int ans=0;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(S1[i-1]==S2[j-1])//substring match kar gya
                {
                    t[i][j]=1+t[i-1][j-1];//count badha lo
                    ans=max(ans,t[i][j]);//store kara lo max count ko
                }
                else//iska matlb match nai kiya toh sequence toot gya
                    t[i][j]=0;//phir se start karo longest common nekalna
            }
        }
        return ans;
    }