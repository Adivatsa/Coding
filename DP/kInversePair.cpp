    int maxval=1000000007;
        
    //int t[1001][1001];
    int inversepair(int n, int k)
    {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        
        //Memoization Step
        if(t[n][k]!=-1)
            return t[n][k];
        
       int count=0;
        //check for all the posible inversion
        //to maintain from overflow min has been taken
        for(int i=0; i<=min(n-1, k); i++)
        {
            count=(count+ inversepair(n-1, k-i))%maxval;
        }
        return t[n][k]=count;
    }
    
    int kInversePairs(int n, int k) {
        
        //Recursion Approach
        
        //Here we can find that we have 1 to n and if we put n+1 to 1 position then it will have 1 inversion
        //again we will put 2 steps left then 2 inversions
        //if we will put to start then it will have n-1 inversion total remaing inversion will be n-k where n=4 and k=4 so 0
        
        //Memoization 
        // vector<vector<int>> t(n+1, vector<int> (k+1,-1));
        memset(t,-1, sizeof(t));
        return inversepair(n,k);
        
//         //Tabulation Approach
//         //vector<vector<int>> t(n+2, vector<int> (k+2,0));
//         int t[1001][1001]={0};
//         // building answer for all values of N starting 1 going upto N
//         for (int i = 0; i < n+1; i++) {

//             for (int j = 0; j < k+1; j++) {
//                 if (j == 0) {
//                     // since J is 0,  sorted case would make it count to 1q
//                     t[i][j] = 1;
//                 }
//                 else {
//                     for (int p = 0; p <= min(j, i - 1); p++)
//                         t[i][j] = (t[i][j] + t[i - 1][j - p]) % 1000000007;
//                 }
//             }
//         }
//         return t[n][k];
    }