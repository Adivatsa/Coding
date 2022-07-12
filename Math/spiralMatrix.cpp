    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        //number of rows
        int m=matrix.size();
        
        //Number of Column
        int n=matrix[0].size();
        
        //top at 0th row and bottom at last row
        //left at 0th column and right at last column
        //0 means left to right , 1 means top to down , 2 means right to left, 3 means bottom to top
        
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        
        //write in  notebook  to visulize better
        int dir=0;
        
        while(left<=right && top<=bottom)
        {
            if(dir==0)
            {
               for(int i=left; i<=right; i++)
                   ans.push_back(matrix[top][i]); 
                top++;
            }
            else if(dir==1)
            {
                for(int i=top; i<=bottom; i++)
                   ans.push_back(matrix[i][right]);
                  right--;
            }
            else if(dir==2)
            {
                for(int i=right; i>=left; i--)
                   ans.push_back(matrix[bottom][i]);
                 bottom--;
            }
            else if(dir==3)
            {
                for(int i=bottom; i>=top; i--)
                   ans.push_back(matrix[i][left]);
                 left++;
            }
            //move to new direction
            dir=(dir+1)%4;
        }
        return ans;
        
    }