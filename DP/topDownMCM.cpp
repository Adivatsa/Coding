    int t[101][101];
    int solve(int i, int j, int arr[])
    {
        //Base condition
        //Think of the termination or invalid condtion
        //When i will be greater or eqaul then j
        //Equal is also considerd as matrix requires atleat two indices
        if(i>=j)
            return 0;
        
        //Check in table
        if(t[i][j]!=-1)
            return t[i][j];
         
        int mini=INT_MAX;  
        //Partion into k parts from i to j
        for(int k=i; k<j; k++)
        {
            //Take from i to k then k+1 to j then joing both the matrices
            int currAns=solve(i,k,arr)+solve(k+1, j,arr)+(arr[i-1]*arr[k]*arr[j]);

                mini=min(currAns,mini);
        }
        //if value is equal to -1 then store in table and then return it
        return t[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // Top Down Code or Memoization
        //In we have make table for changing variables
        //Just assign table with -1 values to all
        //if any call is made store then return 
        //Check if in table value not equal to -1 then return only that value
        //Return the minimum cost
        
        int i=1;
        int j=N-1;
        memset(t, -1,sizeof(t));
        int ans=solve(i,j,arr);
        return ans;
    }