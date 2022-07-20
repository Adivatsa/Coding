    int solve( string &s, string &ss, int i, int j, vector<vector<int>> &t)
    {
        //Base case
        //When string s has been traversed fully
        //then we have make insertion of j+1 to make string ss
        if(i<0)
            return j+1;
        
        //When string ss have been traversed fully then we have to i=1 deletions
        if(j<0)
            return i+1;
        
        //Memoization Step
        if(t[i][j]!=-1)
            return t[i][j];
        //Take out all the possiblities 
        //when  matched
        if(s[i]==ss[j])
            return t[i][j]=solve(s, ss, i-1, j-1,t);
        
        //Otherwise
        
            //Three operation Insert, Delete, Replace
            //Insert an element then i will not decrease as insert happen at i+1 position with ss[j] element , so one operation has been done
            int ins= 1+ solve(s,ss, i, j-1,t);
            
            //Delete operation where deletion has been done from string s and we have to match with ss string
            int del=1 + solve(s,ss, i-1, j,t);
            
            //Replace operation means we have replaced in string s with correct character from ss[j]
            int rep= 1+ solve(s,ss,i-1,j-1,t);
            
        //Return the minimum among them which takes less operation
            return t[i][j]=min(ins, min(del, rep)); 
    }
    int minDistance(string word1, string word2) {
        
        //Recursion Approach #TLE
        int n=word1.length();
        int m=word2.length();
        
        //Memoization Step
        // vector<vector<int>> t(n, vector<int> (m,-1));
        // return solve(word1, word2, n-1, m-1,t);
        
        //Tabulation so convert into 1 based indexing
        vector<vector<int>> t(n+1, vector<int> (m+1,0));
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if(i==0)
                    t[i][j]=j;
                if(j==0)
                    t[i][j]=i;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(word1[i-1]==word2[j-1])
                    t[i][j]= t[i-1][j-1];
                else
                    t[i][j]= min(1+ t[i][j-1], min(1+ t[i-1][j-1], 1+t[i-1][j]));
            }
        }
        return t[n][m];
        
        //Space Optimization
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=0; j<m+1; j++)
            {
                prev[j]=j;
            }
        
        for(int i=1; i<n+1; i++)
        {
            curr[0]=i;
            for(int j=1; j<m+1; j++)
            {
                if(word1[i-1]==word2[j-1])
                    curr[j]= prev[j-1];
                else
                    curr[j]= 1+ min(curr[j-1], min(prev[j-1], prev[j]));
            }
            prev=curr;
        }
        return prev[m];
    }
