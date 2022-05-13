int t[101][101];

    int matrixMultiplication(int N, int arr[])
    {
        
        
        //Bottom Up DP approach
        //here we know that i can be less than or equal to j
        //i will go from n-1 to 1
        //and j will be i+1 to n-1
        
        
        //Intialization step
        
        
        for(int i=0; i<N; i++)
        {

                    t[i][i]=0;
            
        }
        
        for(int i=N-1; i>0; i--)
        {
            for(int j=i+1 ; j<N; j++)
            {
                t[i][j]=INT_MAX;
                for(int k=i; k<j;k++)
                {
                    t[i][j]=min(t[i][k]+t[k+1][j]+(arr[i-1]*arr[k]*arr[j]), t[i][j]);
                }
                    
            }
        }
        return t[1][N-1];
    }