int t[501][501];

//Pass by reference is used to reduce the complexity otherwise give TLE in gfg
    bool ispalindrome(string &s, int i, int j)
    {

        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            else
                {
                    i++;
                    j--;
                }
        }
        return true;;
    }
    int solve(string &s, int i, int j)
    {
        //Base condtion
        if(i>=j)
            return 0;
        
        if(ispalindrome(s,i,j)==true)
        {
            return 0;
        }
        
        if(t[i][j]!=-1)
            return t[i][j];
        int mini=INT_MAX;
        //k will used to partiotion between i to j-1 as j will be taken then will rule out of string
        for(int k=i; k<j; k++)
        {
            int currAns= solve(s,i,k)+solve(s,k+1,j)+1;
            mini=min(currAns,mini);
        }
        
        return t[i][j]=mini;
    }
    int palindromicPartition(string str)
    {

        
        //Method 2: Memoization Top Down approach
        int i=0;
        int j=str.size()-1;
        memset(t,-1, sizeof(t));
        return solve(str,i,j);
    }