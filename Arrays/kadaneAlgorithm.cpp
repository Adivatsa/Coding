class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        //Brute force approach
        //Find out all the subarray and calculate the max sum
        //For finding the all subarray we have to run two for loop
        //first i from 0 to N and second j from i to N then upadate max everytime 
        //TC=O(n^2) Sc=O(1)
        
        //kadane's algorithm
        //yaha pe humme ek currsum and maxsum le lo 
        //currsum will calculate the sum till that element
        //maxsum will calculate maximum sum till that element it may or not include some elemets
        
        //It might possible that all will be negative so intialise with negative infinity
        long long maxSum=INT_MIN;
        long long currSum=INT_MIN;
        
        for(int i=0; i<n ; i++)
        {
            //Step1: calcuate the curr sum
            currSum=currSum+ arr[i];
            
            //Step2: compare kar element and currSum ko jo jyada hga wo currSum hga
            if(currSum<arr[i])
                currSum=arr[i];
            
            //Step3: Upate now maxSum if it is greater than older maxsum
            if(currSum>maxSum)
                maxSum=currSum;
        }
        
        return maxSum;
        
    }
};