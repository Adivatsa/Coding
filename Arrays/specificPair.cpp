int findMaxValue(vector<vector<int>>& mat, int n) {
	    
    int t[n][n];
    
    //we have first process from second row and second columm as a>c and b>d
    t[0][0]=mat[0][0];
    for(int i=1; i<n; i++)//fill with minimum value
        t[i][0]=min(t[i-1][0],mat[i][0]);
    for(int j=1; j<n; j++)
        t[0][j]=min(t[0][j-1],mat[0][j]);
    

    
    int maxi=INT_MIN;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            maxi=max(maxi,(mat[i][j]-t[i-1][j-1]));//a>c and b>d satisfy the diagnonal 
            t[i][j]=min(mat[i][j] ,min(t[i][j-1], t[i-1][j]));//update the minimum value
        }
    }
    return maxi;
}