    long long int count(int S[], int m, int n) {
        
        //m is number of coin and n is sum
        // In this question we have to find count the ways of getting subset sum equal to sum
        //It has been given that infinite supply of each coin so it is unbounded kanpsack
        //We have to make choice to take it or so it is similar to knapsack problem
        //Count the ways so that subset sum equal to given sum
        
        long long int t[m+1][n+1];
        
        for(int i=0; i<m+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(S[i-1] <= j)
                    t[i][j]=t[i][j-S[i-1]] + t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[m][n];
    }