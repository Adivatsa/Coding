    int maxProfit(vector<int>& prices) {
        
        //In this question at most we can buy two stock and sell to get max profit
        //But only one stock at a time
        //Main logic what we will do we will divide the price array into two parts
        //It is divided in a such a way that both will give max profit
        //so one side will be from Left to right and other half will be right to left
        //So in first half we have already purchased i.e. first elementso we have to sell at max limit 
        //While in second half we have to purchase at low cost as sell is alrady decided i.e. last one
        //Consider two vector to store the max profit and at last add max of these two with divided at same point
        //consider left half from 0 to divided line -1 and right half from divided line to n(size-1)
        
        int n=prices.size();
        int profit=0;
        vector<int> left(n),right(n);//Two vector creation
        left[0]=0;//intial profit =0
        right[n-1]=0;//intial profit=0
        int mini=prices[0];//buy at start
        int maxi=prices[n-1];//sell at end
        //This will fill left vector where intailly stock buyed at start
        for(int i=1; i<prices.size(); i++)
        {
            left[i]=max(left[i-1], prices[i]-mini);//update profit
            mini=min(mini,prices[i] );//update stock price if any new less price stock came
        }
        //This will be for right vector where intially stock will be sold at last 
        for(int i=prices.size()-2; i>=0; i--)
        {
            right[i]=max(right[i+1], maxi-prices[i]);
            maxi=max(maxi,prices[i] );//update any high value to sell comes
        }
        //Just compare with earlier profit and if we divide into two parts sum 
        //Update the max profit
        for(int i=0; i<prices.size(); i++)
        {
            profit=max(profit, left[i]+right[i]);
        }
        
        return profit;
    }