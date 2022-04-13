	int minDifference(int arr[], int n)  { 
	    // main aim of this is to find the minimum difference between two subsets
	    //if we are dividing into two parts then s1 and s2 
	    //s1 and s2 will lie between 0 to total sum
	    //s2=sum-s1 use this to get s1-s2 as min
	    //it can be reduced to sum-2*s1 which is to be minimum
	    
	    //Step 1: find the range
	    int sum=0;
	    for(int i=0; i<n ; i++)
	        sum+=arr[i];
	        
	   //step2: find the subset sum 
	   
	   bool t[n+1][sum+1];
	   
	   //intialization process
	   for(int i=0; i<n+1; i++)
	   {
	       for(int j=0; j<sum+1; j++)
	       {
	           if(i==0)
	                t[i][j]=false;
	            if(j==0)
	                t[i][j]=true;
	       }
	   }
	   //subset sum matrix calculation
	   for(int i=1; i<n+1; i++)
	   {
	       for(int j=1; j<sum+1; j++)
	       {
	           if(arr[i-1] <= j)
	           {
	               t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
	           }
	           else 
	           {
	               t[i][j]= t[i-1][j];
	           }
	       }
	   }
	   //just process the last row 
	   //in that also half first half as we have considered as s1 will be less than sum/2
	   //if any true found from last postion then just calculate differenece with sum - 2*j which will be always minimum
	   int diff=INT_MAX;
	   for(int j=sum/2; j>=0 ; j--)
	   {
	       if(t[n][j]==true)
	       {
	           diff=sum-2*j;
	           break;
	       }
	   }
	   return diff;
	}