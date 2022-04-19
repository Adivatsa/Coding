int minCoins(int coins[], int M, int V) 
	{ 
	    // in this question we have find minimum no of coins to get sum
	    //V is given as the sum and M is number of coins
	    //This question given with infinte coin supply so unbounded knapsack problem
	    
	    int t[M+1][V+1];
	    
	    //intialization step
	    //isme ek case hai jab sum 0 se bada ho aur number of coin 0 ho tb infinite coins require to get sum as given 
	    //jabki if sum is 0 and number of coins greater than 0 then we require simply no coin or 0 coin to get sum 0
	    for(int i=0; i<M+1; i++)
	    {
	        for(int j=0; j<V+1; j++)
	        {
	            if(i==0)
	                t[i][j]=INT_MAX-1;
	           if(j==0)
	                t[i][j]=0;
	        }
	    }
	    
	    //for the second row in which only first coin has to be considerd and sum as 1 to V
	    //In this if first coin is not multiple of sum then it is not possiblle to store the coin
	    //Check if the given first coin is multiple of sum then put the multiple of it
	    //otherwise place INT_MAX-1 as the value
	    
	    for(int i=1, j=1; j<V+1; j++)
	    {
	        if(j%coins[0]==0)
	        {
	            t[i][j]=j/coins[0];
	        }
	        else
	            t[i][j]=INT_MAX-1;
	    }
	    //in this take the min of including that coin and not including it
	    for(int i=2; i<M+1; i++)
	    {
	        for(int j=1; j<V+1; j++)
	        {
	            if(coins[i-1] <= j)
	                t[i][j]=min(1+ t[i][j-coins[i-1]], t[i-1][j]);
	           else
	                t[i][j]=t[i-1][j];
	        }
	    }
	    //before return check if it is int max then return -1 otherwise ans
	    if(t[M][V]==INT_MAX-1)
	        return -1;
        else
	        return t[M][V]; 
	}