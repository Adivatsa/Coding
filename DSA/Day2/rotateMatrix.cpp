    void rotate(vector<vector<int>>& matrix) {
        
        //Method 1: take one extra matrix to store transpose of a matrix
        //Step1: transpose a matrix and store in new matrix
        //reverse each row
        //TC=(n^2)
        //SC=O(n^2)
        
        //Method 2: In this transpose using inplace matrix
        //just reverse the each row 
        //TC=SC=O(n^2)
        
        //row
        int r=matrix.size();
       
        //Transpose of a Matrix
        for(int i=0; i<r; i++)
        {
            for(int j=i+1; j<r; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        for(int i=0; i<r; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        
    }