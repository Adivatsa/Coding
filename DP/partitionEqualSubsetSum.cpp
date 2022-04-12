    int isSubsetSum(int arr[], int n, int sum)
    {
        int t[102][10002];

        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                //step 1 : intialization
                if(i==0)//array size is 0 but sum is more than 0 which is impossible
                    t[i][j]=0;
                if(j==0)//sum is 0
                    t[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
               if(arr[i-1] <= j)//subset jo hai sum se chota hai & decide to include or not
                {
                    t[i][j]= t[i-1][j-arr[i-1]]  || t[i-1][j];
                }
                else 
                {
                    t[i][j]=t[i-1][j];
                }
                    
            }
        }
        
        return t[n][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        //we have to divide arr into two parts with equal sum
        //if sum is odd then we can not divide into two parts
        //if sum is even means we can divide into two parts with equal sum
        //for that just search for subset sum with sum as sum/2
        //automatically other half will be present
        
        //TC=O(n*sum) SC=O(n*sum)
        
        //step1 : calculate sum
        int sum=0;
        for(int i=0; i<N ; i++)
            sum=sum+arr[i];
        
        //step2: Check is equal to odd then return false 
        if(sum%2!=0)
            return 0;
        
        return isSubsetSum(arr,N,sum/2);
    }