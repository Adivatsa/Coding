int t[1002][1002];//Matrix for table
    
    /*int memoizationKanpsack(int W, int wt[], int val[], int n)
    {
        //Base case
        //When input will be small 
        if(n==0 || W==0)
            return 0;
        
        //Check for if value is already present in table just return that value
        if(t[n][W] != -1)
            return t[n][W]; //just return the value
        
        //Recursive call function 
        //check for weight is less than kanpsack bag then add value and do more subproblem
        if(wt[n-1] <= W)//Check if it can be included or not included
            return (t[n][W]=max(val[n-1] + memoizationKanpsack(W-wt[n-1],wt,val,n-1) , memoizationKanpsack(W,wt,val,n-1)));
        else if(wt[n-1] > W)
            return (t[n][W]=memoizationKanpsack(W,wt,val,n-1));
            
    }*/
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //In this question it has been discussed that one quantity of each so it is not unbounded knapsack
        //Now it has been also given that u can not break an item so it is not frational knapsack
       
        /*
        //Method 1: Using Recursion method(TLE at 1137 test case)
        TC=O(2^n) SC=O(n*m)
        
        //Base case
        //When input will be small 
        if(n==0 || W==0)
            return 0;
        
        //Recursive call function 
        //check for weight is less than kanpsack bag then add value and do more subproblem
        if(wt[n-1] <= W)//Check if it can be included or not included
            return max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1) , knapSack(W,wt,val,n-1));
        else if(wt[n-1] > W)
            return knapSack(W,wt,val,n-1);
        */
        /*
        //Method 2: Memoization Approach
        //This method is based on recursion with table
        //TC= O(n*m) and SC=(n*m)
        
        
        /*
        //filling the table of size t[n+1][W+1] with -1 as a value
        for(int i=0 ;i<n+1; i++)
            for(int j=0; j<W+1; j++)
                t[i][j]=-1;
        
        memset(t,-1,sizeof(t));
        
        //call for memoization kanpsack
        return memoizationKanpsack(W,wt,val,n);
        */
        
        //Method 3: Tabulation Approach(Using only table)
        //This method is iterative approach with base to top 
        //we will fill the table from 0 to end and return last as max profit
        
        //Like recursive method has base case it has intialization first row and first column to 0
        //Step 1: intialization
        //It is iterative approach so start from 1 to n & t to W
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<W+1; j++)
            {
                if(i==0 || j==0)//intializing 1st row and 1st column to 0
                    t[i][j]=0;
                
                else if(wt[i-1]<= j)//check for if weight less than current bag capacity 
                {
                    t[i][j]= max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);//check if it to be included or not included
                }
                else if(wt[i-1] > j)//if weight is greater than kanapsack bag capacity 
                {
                    t[i][j]= t[i-1][j];//dont include 
                }
            }
        }
        
        return t[n][W];//return last value
        
    }