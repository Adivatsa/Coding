    int t[101][101];
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //Supersequence banana hai jisme dono string present ho
        //Supersequence jo hai woh shortest hona chahiye
        //Brute force me dono string ke length ko add maar do whi ho jaayega supersequence
        //Lekin agar kuch common subsequenece present hai toh woh do baar likhe ja rhe hai
        //Shortest karne ke liye ek baar nikal do
        
        //Step1: LCS ka length nekaal lo
        //Intialization
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
                if(X[i-1]==Y[j-1])
                    t[i][j]=1+ t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
            }
        }
        return m+n-t[m][n];//Total length- Repeated part(LCS)
    }