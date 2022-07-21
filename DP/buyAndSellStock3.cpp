    int solve(vector<int>& prices, int index, int canBuy, int transac, vector<vector<vector<int>>> &t)
    {
        //Base Case
        //if 2 transaction completed or all has been traversed
        if(transac==0)
            return 0;
        if(index==prices.size())
            return 0;
        
        //Memoization Step
        if(t[index][canBuy][transac]!=-1)
            return t[index][canBuy][transac];
        int profit=0;
        //here we have two possibilities 
        //we can buy stock
        if(canBuy==1)
        {
           profit= max(-prices[index] + solve(prices, index+1, 0,transac,t), 0+ solve(prices, index+1, 1,transac,t)); 
        }
        else//we can only sell Stock
        {
            //selling ahs also two possiblities can sell or not sell 
            //if sold one transaction completed
            profit= max(prices[index] + solve(prices, index+1, 1,transac-1,t), 0+ solve(prices, index+1, 0,transac,t));
        }
        return t[index][canBuy][transac]=profit;
    }
    
    int solve1(vector<int>& prices , int index, int tno, vector<vector<int>> &t )
    {
        //Base case
        if(tno==4)
            return 0;
        if(index== prices.size())
            return 0;
        
        //Memoization Step
        if(t[index][tno]!=-1)
            return t[index][tno];
        int profit=0;
        //only can buy
        if(tno%2==0)
        {
            profit= max( -prices[index] + solve1(prices,index+1,tno+1,t ), 0+ solve1(prices, index+1, tno,t));
        }
        else
        {
            profit= max( prices[index] + solve1(prices,index+1,tno+1,t ), 0+ solve1(prices, index+1, tno,t));
        }
        return t[index][tno]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
//         //In this question at most we can buy two stock and sell to get max profit
//         //But only one stock at a time
//         //Main logic what we will do we will divide the price array into two parts
//         //It is divided in a such a way that both will give max profit
//         //so one side will be from Left to right and other half will be right to left
//         //So in first half we have already purchased i.e. first elementso we have to sell at max limit 
//         //While in second half we have to purchase at low cost as sell is alrady decided i.e. last one
//         //Consider two vector to store the max profit and at last add max of these two with divided at same point
//         //consider left half from 0 to divided line -1 and right half from divided line to n(size-1)
        
//         int n=prices.size();
//         int profit=0;
//         vector<int> left(n),right(n);//Two vector creation
//         left[0]=0;//intial profit =0
//         right[n-1]=0;//intial profit=0
//         int mini=prices[0];//buy at start
//         int maxi=prices[n-1];//sell at end
//         //This will fill left vector where intailly stock buyed at start
//         for(int i=1; i<prices.size(); i++)
//         {
//             left[i]=max(left[i-1], prices[i]-mini);//update profit
//             mini=min(mini,prices[i] );//update stock price if any new less price stock came
//         }
//         //This will be for right vector where intially stock will be sold at last 
//         for(int i=prices.size()-2; i>=0; i--)
//         {
//             right[i]=max(right[i+1], maxi-prices[i]);
//             maxi=max(maxi,prices[i] );//update any high value to sell comes
//         }
//         //Just compare with earlier profit and if we divide into two parts sum 
//         //Update the max profit
//         for(int i=0; i<prices.size(); i++)
//         {
//             profit=max(profit, left[i]+right[i]);
//         }
        
//         return profit;
        
        
        //Recursion Approach
        //Here we have a bound of atmost 2 transaction with buy and sell stock 
        //it can not be done buy two stock at the same time before buying u have to sell prev stock
        //2 means two transaction has to be done and 1 means ready to buy stock
        
        //Memoization Step
        //int n=prices.size();
        // vector<vector<vector<int>>> t(n, vector<vector<int>> (2, vector<int> (3,-1)));
        // return solve(prices, 0, 1,2,t);
        
        //Tabulation Approach
        //int n=prices.size();
        // vector<vector<vector<int>>> t(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
        //Intialization
        //when transaction is 0 then for all index and buy case it will be 0
        //when index==n then canBuy and transac will be zero
        
        //write in reversw direction recursion
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int canBuy=0; canBuy<=1; canBuy++)
//             {
//                 for(int transac=1; transac<=2; transac++)
//                 {

//                     if(canBuy==1)
//                     {
//                          t[index][canBuy][transac]= max(-prices[index] + t[index+1][0][transac],t[index+1][1][transac]); 
//                     }
//                     else//we can only sell Stock
//                     {   
//                         t[index][canBuy][transac]= max(prices[index] + t[index+1][1][transac-1], t[index+1][0][transac]);
//                     }
//                 }
//             }
//         }
//         return t[0][1][2];
        
        
//         //Space optimization Approach
        
//         vector<vector<int>> prev(3, vector<int> (3,0));
//         vector<vector<int>> curr(3, vector<int> (3,0));
        
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int canBuy=0; canBuy<=1; canBuy++)
//             {
//                 for(int transac=1; transac<=2; transac++)
//                 {

//                     if(canBuy==1)
//                     {
//                          curr[canBuy][transac]= max(-prices[index] + prev[0][transac],prev[1][transac]); 
//                     }
//                     else//we can only sell Stock
//                     {   
//                         curr[canBuy][transac]= max(prices[index] + prev[1][transac-1], prev[0][transac]);
//                     }
//                 }
//             }
//             prev=curr;
//         }
//         return prev[1][2];
        
        
        //Another Approach using index and transaction number
        //At maximum we can have 4 transaction Buy(0) Sell(1) Buy(2) Sell(3)
        //At even place we can buys and odd place we can sell the stock
        
        // Step 1: Using Recursion 
        
        int n=prices.size();
        
        //Step 2: Memoization Step
        //vector<vector<int>> t(n, vector<int> (4,-1));
        //return solve1(prices,0, 0,t);
        
        //Step 3: Tabulation Approach
        
//         vector<vector<int>> t(n+1, vector<int> (5,0));
        
//         //intialization Step:
        
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int tno=3; tno>=0; tno--)
//             {
//                 //only can buy
//                 if(tno%2==0)
//                 {
//                     t[index][tno]= max( -prices[index] + t[index+1][tno+1], t[index+1][tno]);
//                 }
//                 else
//                 {
//                     t[index][tno]= max( prices[index] + t[index+1][tno+1] , t[index+1][tno]);
//                 }
//             }
//         }
//         return t[0][0];
        
        //Space Optimization
        vector<int> prev(5,0);
        vector<int> curr(5,0);
        
        for(int index=n-1; index>=0; index--)
        {
            for(int tno=3; tno>=0; tno--)
            {
                //only can buy
                if(tno%2==0)
                {
                    curr[tno]= max( -prices[index] + prev[tno+1], prev[tno]);
                }
                else
                {
                    curr[tno]= max( prices[index] + prev[tno+1] , prev[tno]);
                }
            }
            prev=curr;
        }
        return prev[0];
        
    }
