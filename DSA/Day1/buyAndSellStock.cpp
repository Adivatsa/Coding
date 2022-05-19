int maximumProfit(vector<int> &prices){
    	
	
	int profit=0;
	int temp=prices[0];
	
	for(int i=1; i<prices.size(); i++)
	{
		temp=min(temp, prices[i]);
		profit=max(profit, prices[i]-temp);
	}
	return profit;
}