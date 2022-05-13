int solve(int i, int j, int arr[])
    {
        //Base condition
        //Think of the termination or invalid condtion
        //When i will be greater or eqaul then j
        //Equal is also considerd as matrix requires atleat two indices
        if(i>=j)
            return 0;
         
        int mini=INT_MAX;  
        //Partion into k parts from i to j
        for(int k=i; k<j; k++)
        {
            //Take from i to k then k+1 to j then joing both the matrices
            int currAns=solve(i,k,arr)+solve(k+1, j,arr)+(arr[i-1]*arr[k]*arr[j]);

                mini=min(currAns,mini);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // Recursive Code
        //We have for think of value of index which starts and end
        //Then call for every K value
        //Calculate the cost value for each k partition
        //Return the minimum cost
        
        int i=1;
        int j=N-1;
        
        int ans=solve(i,j,arr);
        return ans;
    }