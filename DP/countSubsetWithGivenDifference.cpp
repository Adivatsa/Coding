
int countSubset(int arr[], int n, int diff)
{
    //here main logic is we have to find out the count the number of subset with given difference
    //Array of elements dia hua hga and deiference dia hga between two subset jo hona chahiye
    //consider two subset as s1 and s2 so (s1-s2)=difference
    //And we also know total sum of both subset as array sum s1+s2=sum(array)
    //Solve both the eqaution we get s1=sum(arr)+ difference/2
    //just count the number of subset sum equal to s1
    //that many will be count of subset sum with given difference
    //Note just check if sum+difference is odd that means no any subset will be possible 
    //It has been given array of integers so fractional part will be neglected 
    //so in this case subset sum will not be possible

    //Step1: Calculate sum
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=arr[i];

    //Step2: find the subset sum
    //check if it is odd or not
    if((sum+diff)%2==1)
        return 0;

    sum=diff+sum/2;

    //Step 3: matrix intialization
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

    //Step4: find count for the given sum
    for(int i=1 ; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(arr[i-1] <=j)
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
            
            else
                t[i][j]=t[i-1][j];
            
        }
    }
    //Step5: return the count
    return t[n][sum];

}
    

    