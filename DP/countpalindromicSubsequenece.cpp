int t[1001][1001];
    int m=1000000007;
    long long int countall(string &s,int i, int j)
    {
        //i start me hga and j end mw hga
        //i agr j se aage nekal jaaye toh 0 daal do
        //i and j equal hai matlb single charater thn return 1
        //otherwise two condition for palindromic subsequence
        //first condn: 1st and last characyer are equal then we have to take from
        //abdca here c1=a, m=bdc, c2=a then c1 ==c2 then find for bdca, abdc then abdca which is palindrome so add 1
        //while condition 2 if both are not equal then just itertate both
        //and subtract the repetaed midddle part
        if(i>j)
            return t[i][j]=0;
        
        if(i==j)
            return t[i][j]=1;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        if(s[i]==s[j])
            return t[i][j]=(m+countall(s,i+1,j)%m+countall(s,i,j-1)%m+1)%m;//negative ans add m
        else
            return t[i][j]=(m+countall(s,i+1,j)%m+countall(s,i,j-1)%m-countall(s,i+1,j-1)%m)%m;//add m to recover from negative ans
    }
    long long int  countPS(string str)
    {
       int n=str.size();
        //t[n][n];
        memset(t,-1,sizeof(t));
        return countall(str,0,n-1);
    }