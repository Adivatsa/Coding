    int solve(vector<int>& prices, int fee, int index, int canBuy, vector<vector<int>> &t)
    {
        //Base case
        if(index==prices.size())
            return 0;
       
        //Memoization Step
        if(t[index][canBuy]!=-1)
            return t[index][canBuy];
        if(canBuy==1)
        {
            return t[index][canBuy]=max(-prices[index] + solve(prices, fee, index+1, 0,t), solve(prices, fee, index+1, 1,t));
        }
        else
            return t[index][canBuy]=max(prices[index]-fee + solve(prices, fee, index+1, 1,t), solve(prices, fee, index+1, 0,t));
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        //Recursion Approach
        int n=prices.size();
        
        //Memoization Step
        //vector<vector<int>> t(n, vector<int> (2,-1));
        //return solve(prices, fee, 0, 1,t);
        
        //Tabulation Approach
//         vector<vector<int>> t(n+1, vector<int> (2,0));
        
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int canBuy=0; canBuy<=1; canBuy++)
//             {
//                 if(canBuy==1)
//                     t[index][canBuy]=max(-prices[index] + t[index+1][0],t[index+1][1]);
//                 else
//                     t[index][canBuy]=max(prices[index]-fee + t[index+1][1],t[index+1][0]);
//             }
//         }
//         return t[0][1];
        
        //Space optimization
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        
        for(int index=n-1; index>=0; index--)
        {
            for(int canBuy=0; canBuy<=1; canBuy++)
            {
                if(canBuy==1)
                    curr[canBuy]=max(-prices[index] + prev[0],prev[1]);
                else
                    curr[canBuy]=max(prices[index]-fee + prev[1],prev[0]);
            }
            prev=curr;
        }
        return prev[1];
    }