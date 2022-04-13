int findTargetSumWays(vector<int>& nums, int target) {
        
        //problem similar to count subset sum with given difference
        //here the differenece given is target
        //we have to return the count
        //difference can be negative take absolute value
        //in second loop j start from 0 bcz to include sum as 0
        //it is possible that array contain only 0, 0, 0 .. and sum is also 0
        target=abs(target);
        //Step1: find sum and no of 0's
        int sum=0;

        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
        }
        
        //Step2: Check if sum+difference is odd then retirn 0 as it can't be possible
        if(target>sum || (sum+target)%2==1)
            return 0;
        sum=(sum+target)/2;
        
        //Step3: intialization of matrix
        int n=nums.size();
        int t[n+1][sum+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        //Step4: Find count for the given subset sum
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)//as we know that array may contain 0 as integer
            {
                if(nums[i-1] <= j)
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
        //Step5: Return the result
        return t[n][sum];
    }