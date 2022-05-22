    int countSubstrings(string s) {
        
        //single length substring will be always be palindrome
        //for two length just check using loop 
        //for len>3 use dp table where if first last are equal then just only go for second to second last
        //we have to go in diagonal manner filling the table of dp
        //use variable to itertate in diagonal manner
        int n=s.size();
        int count=0;
        bool t[n][n];
        
        for(int d=0; d<n; d++)
        {
            for(int i=0,j=d; j<n;i++,j++)
            {
                
                if(d==0)
                {
                    t[i][j]=true;
                }
                else if(d==1)
                {
                    if(s[i]==s[j])
                        t[i][j]=true;
                    else
                        t[i][j]=false;
                }
                else
                {
                    if(s[i]==s[j])//first and last are equal
                    {
                        t[i][j]=t[i+1][j-1];//check from dp table for previous second to second last
                    }
                    else
                        t[i][j]=false;
                }
                if(t[i][j]==true)
                {
                    count++;
                }
            }
        }
        return count;  
    }