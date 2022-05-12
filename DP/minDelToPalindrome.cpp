int t[1001][1001];
int minDeletions(string str, int n) { 
    
    //minimum deletion is when we have largest palindromic subsequence
    //we have make to palindrome string
    //find one more string so that to obtain longest palindromic subsequence
    //just subtract string lenth - LPS
    string str1=str;
    reverse(str.begin(), str.end());
    int m=str1.length();
    
    
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
            if(str1[i-1]==str[j-1])
                t[i][j]=1+ t[i-1][j-1];
            else
                t[i][j]=max(t[i-1][j], t[i][j-1]);
        }
    }
    return m-t[m][n];
    
} 