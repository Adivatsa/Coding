    int solve(vector<int>& prices, int index, int canBuy, vector<vector<int>> &t)
    {
        //Base case
        //when any stock bought but didnot sell so 0 profit
        if(index==prices.size())
            return 0;
        if(t[index][canBuy]!=-1)
            return t[index][canBuy];
        int profit=0;
        //we can buy
        if(canBuy==1)
        {
          //here we have two condition we can or we can not buy as stock price is high
            //we have to find the maximum, BUY means spending money
            profit=max(-prices[index]+ solve(prices,index+1, 0,t), 0+solve(prices,index+1, 1,t));
        }
        else//we can only sell already bought one stock
        {
            //here we can sell or not sell based upon criteria
            //selling means earning money we have to find maz
            profit=max(prices[index] + solve(prices,index+1, 1,t), 0+solve(prices,index+1, 0,t));
        }
        return t[index][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        //In this we can buy and sell any number of times
        //Hold one share at a time
        //Just check for each day and if i greater than i-1th day then it has profit 
        //just increase in profit
        
       //  int profit=0;
       //  for(int i=1; i<prices.size(); i++)
       //  {
       //      if(prices[i-1]<prices[i])
       //      {
       //          profit=profit + (prices[i]-prices[i-1]);
       //      }
       //  }
       // return profit;
        
        //Recursion Approach
        //here if we have already bought then we can not buy other stock
        //1 means u can buy and 0 means u can not buy
        
        
        //Memoization step
        int n=prices.size();
        int m=2;
        // vector<vector<int>> t(n, vector<int>(m,-1));
        // return solve(prices,0,1,t);
        
        //Tabulation Step
        vector<vector<int>> t(n+1, vector<int>(m,0));
        // t[n][0]=t[n][1]=0;
        // for(int index=n-1; index>=0; index--)
        // {
        //     for(int canBuy=0; canBuy<=1; canBuy++)
        //     {
        //         int profit=0;
        //         //we can buy
        //         if(canBuy==1)
        //         {
        //           //here we have two condition we can or we can not buy as stock price is high
        //             //we have to find the maximum, BUY means spending money
        //             profit=max(-prices[index] + t[index+1][0], t[index+1][1]);
        //         }
        //         else//we can only sell already bought one stock
        //         {
        //             //here we can sell or not sell based upon criteria
        //             //selling means earning money we have to find maz
        //             profit=max(prices[index] + t[index+1][1] , t[index+1][0]);
        //         }
        //         t[index][canBuy]=profit;
        //     }
        // }
        // return t[0][1];
        
        //Space optimization Approach
        
        vector<int> prev(2,0), curr(2,0);
        
        prev[0]=prev[1]=0;
        for(int index=n-1; index>=0; index--)
        {
            for(int canBuy=0; canBuy<=1; canBuy++)
            {
                int profit=0;
                //we can buy
                if(canBuy==1)
                {
                  //here we have two condition we can or we can not buy as stock price is high
                    //we have to find the maximum, BUY means spending money
                    profit=max(-prices[index] + prev[0], prev[1]);
                }
                else//we can only sell already bought one stock
                {
                    //here we can sell or not sell based upon criteria
                    //selling means earning money we have to find maz
                    profit=max(prices[index] +prev[1] ,prev[0]);
                }
                curr[canBuy]=profit;
            }
            prev=curr;
        }
        return prev[1];
        
        
    }
