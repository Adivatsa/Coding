    int t[2001][2001];
    bool ispalindrome(string &s, int i, int j)
    {
        if(i==j)
            return true;
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
        if(t[i][j]!=-1)
            return t[i][j];
        //Base condtion
        if(i>=j || ispalindrome(s,i,j)==true )
        {
            t[i][j]=0;
            return 0;
        }
        
        int mini=INT_MAX;
        //k will used to partiotion between i to j-1 as j will be taken then will rule out of string
        for(int k=i; k<j; k++)
        {
            if(ispalindrome(s,i,k))//left part has been already checked if it will palindrome go to right
               {
                    int currAns= solve(s,k+1,j)+1;
                    mini=min(currAns,mini);
               }
 
        }
        
        return t[i][j]=mini;
    }
    int minCut(string s) {
        

        int i=0;
        int j=s.size()-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j);
        
       
    }