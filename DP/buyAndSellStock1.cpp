    int maxProfit(vector<int>& prices) {
        
        //In this question it ahs been asked about one time to buy the stock and sell once
        //Check findout out global minima and maxima occured after that
        
        int mini=prices[0];
        int profit=0;
        for(int i=1; i<prices.size(); i++)
        {
            mini=min(mini, prices[i]);
            profit=max(profit, prices[i]-mini);
        }
       return profit; 
    }