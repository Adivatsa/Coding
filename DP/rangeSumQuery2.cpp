class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        //here we will calculate the prefix sum from left to right then top to bottom
        //find prefix sum matrix
        mat=matrix;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(i>0)
                    mat[i][j]+=mat[i-1][j];
                if(j>0)
                    mat[i][j]+=mat[i][j-1];
                if(i>0 && j>0)
                    mat[i][j]-=mat[i-1][j-1];
            }
        }
 
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //here take the last position and subtract remaining part
        //first it will take from 0,0 to row2, col2
        //then subtract all parts before row1,col1 to desired result
        int ans=0;
        ans= mat[row2][col2];
        if(row1>0)
            ans-=mat[row1-1][col2];
        if(col1>0)
            ans-=mat[row2][col1-1];
        if(row1>0 && col1>0)
            ans+=mat[row1-1][col1-1];
        return ans;
    }
};