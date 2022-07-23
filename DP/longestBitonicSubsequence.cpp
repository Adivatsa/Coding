int LongestBitonicSequence(vector<int>nums)
	{
	    //Bitonic sequenece is increasing then decresing , only increasing, only decreasing
	    
	    //Traverse and store the LIS from Start to End 
	    //Again traverse from END to start 
	    //add both the LIS-1 for common onr and find the maximum
	    
	    int n=nums.size();
	    vector<int> t1(n,1);
	    
	    //From Start to End 
	    for(int index=0; index<n; index++)
	    {
	        for(int pindex=0; pindex<index; pindex++)
	        {
	            if(nums[index]> nums[pindex] && t1[pindex]+1 > t1[index])
	                t1[index]= t1[pindex]+1;
	        }
	    }
	    
	    //From End to Start
	    vector<int> t2(n,1);
	    for(int index=n-1; index>=0; index--)
	    {
	        for(int pindex=n-1; pindex>index; pindex--)
	        {
	            if(nums[index]> nums[pindex] && t2[pindex]+1 > t2[index])
	                t2[index]= t2[pindex]+1;
	        }
	    }
	    
	    //Find the maximum among them by eliminating the same index twice as lis will be from t1:1 to 10 and t2: 10 to 2
	    int maxi=1;
	    for(int i=0; i<n; i++)
	    {
	        maxi=max(maxi, t1[i]+ t2[i]-1);
	    }
	    return maxi;
	}