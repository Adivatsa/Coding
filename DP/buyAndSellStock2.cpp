    int maxProfit(vector<int>& prices) {
        
        //In this we can buy and sell any number of times
        //Hold one share at a time
        //Just check for each day and if i greater than i-1th day then it has profit 
        //just increase in profit
        
        int profit=0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i-1]<prices[i])
            {
                profit=profit + (prices[i]-prices[i-1]);
            }
        }
       return profit; 
    }