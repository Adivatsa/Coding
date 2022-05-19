long long maxSubarraySum(int arr[], int n)
{
    long long maxSum=0;//according to question it has been given that maximum sum is 0
	long long currSum=arr[0];//intailise currsum
	
	for(int i=1; i<n; i++)
	{
		currSum+=arr[i];//sum calculation
		if(currSum<arr[i])//check if after adding sum se chota na ho jaaye like -ve no add kiye toh
		{
			currSum=arr[i];//ush case me subarray whi se start karo
		}
		maxSum=max(currSum,maxSum);//calculate the maximum sum
	}
	return maxSum;
}