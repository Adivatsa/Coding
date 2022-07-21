    int solve(int k, vector<int>& prices, int index, int tno, vector<vector<int>> &t)
    {
        if(index==prices.size() || tno==2*k)
            return 0;
        if(t[index][tno]!=-1)
            return t[index][tno];
        int profit=0;
        
        if(tno%2==0)//Only we can Buy or not Buy
        {
            profit= max(-prices[index]+ solve(k, prices, index+1, tno+1,t), 0 + solve(k, prices, index+1, tno,t));
        }
        else//only sell operation 
        {
            profit=max(prices[index]+solve(k, prices, index+1, tno+1,t), 0 + solve(k, prices, index+1, tno,t));
        }
        return t[index][tno]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        //Recursion Approach
        //Question same as Buy and Sell Stock 3
        //it has atmost k transaction so total transactions will be 2*k
        int n= prices.size();
        
        
        //Memoization Step
        //vector<vector<int>> t(n, vector<int> (2*k,-1));
        //return solve(k,prices, 0,0,t);
        
        //Tabulation Approach
        //vector<vector<int>> t(n+1, vector<int> (2*k+1, 0));
        
        // for(int index= n-1; index>=0; index--)
        // {
        //     for(int tno=2*k-1; tno>=0; tno--)
        //     {
        //         if(tno%2==0)//Only we can Buy or not Buy
        //         {
        //             t[index][tno]= max(-prices[index]+ t[index+1][tno+1], t[index+1][tno]);
        //         }
        //         else//only sell operation 
        //         {
        //             t[index][tno]=max(prices[index]+t[index+1][tno+1], t[index+1][tno]);
        //         }
        //     }
        // }
        // return t[0][0];
        
        
        //Space optimization
        
        vector<int> prev(2*k+1,0);
        vector<int> curr(2*k+1,0);
        
        for(int index= n-1; index>=0; index--)
        {
            for(int tno=2*k-1; tno>=0; tno--)
            {
                if(tno%2==0)//Only we can Buy or not Buy
                {
                    curr[tno]= max(-prices[index]+ prev[tno+1], prev[tno]);
                }
                else//only sell operation 
                {
                    curr[tno]=max(prices[index]+prev[tno+1], prev[tno]);
                }
            }
            prev=curr;
        }
        return prev[0];
        
    }