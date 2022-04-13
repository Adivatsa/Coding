int perfectSum(int arr[], int n, int sum)
	{
        long long m=1e9+7;
        int t[n+1][sum+1];
        
        for(int i=0 ; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        for(int i=1 ; i<n+1; i++)
        {//Most important catch it should start from 0
            for(int j=0; j<sum+1; j++)//if array has 0 then it must add to count so start from index 0
            {
                if(arr[i-1] <=j)//Take all the subset so add both of them 
                    t[i][j]= (t[i-1][j-arr[i-1]]%m + t[i-1][j]%m)%m;
                else//element is greater than just copy the previous count
                    t[i][j]= t[i-1][j]%m;
            }
        }
        
        return t[n][sum];
	}