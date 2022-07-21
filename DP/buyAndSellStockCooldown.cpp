    int solve(vector<int>& prices, int index , int canBuy, vector<vector<int>> &t)
    {
        //Base case
        if(index>=prices.size())
            return 0;
        
        if(t[index][canBuy]!=-1)
            return t[index][canBuy];
        
        int profit=0;
        //for buying
        if(canBuy==1)
        {
            profit= max(-prices[index] + solve(prices, index+1, 0,t), solve(prices, index+1, 1,t));
        }
        else//only sell opertion where if u sell then skip two index so that u can not buy on next day
        {
            profit= max(prices[index] + solve(prices, index+2,1,t), solve(prices, index+1, 0,t));
        }
        
        return t[index][canBuy]=profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        //In this question we have constraint that we can not buy to next day of selling
        //So we will skip with 2 index so that we can not buy on the next day
        
        //Recursion
        int n=prices.size();
        
        //Memoization Step
        //vector<vector<int>> t(n, vector<int> (2,-1));
        //return solve(prices, 0, 1,t); //1 means buy 0 means not allowed to buy
        
        //Tabulation Approach
//         vector<vector<int>> t(n+2, vector<int> (2,0));
        
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int canBuy=0; canBuy<=1; canBuy++)
//             {
//                 //for buying
//                 if(canBuy==1)
//                 {
//                     t[index][canBuy]= max(-prices[index] + t[index+1][0], t[index+1][1]);
//                 }
//                 else//only sell opertion where if u sell then skip two index so that u can not buy on next day
//                 {
//                     t[index][canBuy]= max(prices[index] + t[index+2][1], t[index+1][0]);
//                 }
//             }
//         }
        
//         return t[0][1];
        
        //Space Optimization
        vector<int> prev(2,0);
        vector<int> pprev(2,0);
        vector<int> curr(2,0);
        for(int index=n-1; index>=0; index--)
        {
            for(int canBuy=0; canBuy<=1; canBuy++)
            {
                //for buying
                if(canBuy==1)
                {
                    curr[canBuy]= max(-prices[index] + prev[0], prev[1]);
                }
                else//only sell opertion where if u sell then skip two index so that u can not buy on next day
                {
                    curr[canBuy]= max(prices[index] + pprev[1], prev[0]);
                }
            }
            pprev=prev;
            prev=curr;
        }
        return prev[1];
    }