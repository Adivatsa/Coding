    int minimumTotal(vector<vector<int>>& triangle) {
        
        //In this problem we can aquire from i or i+1 index of next step
        //we will start from bottom to top
        
        int n=triangle.size();
        vector<int> t(n,0);
        
        //copy last row to vector 
        for(int i=0; i<n; i++)
            t[i]=triangle[n-1][i];
        
        //iterate from second last row to top row
        for(int i=n-2; i>=0; i--)
        {
            //traverse over each elelemnt
            for(int j=0; j<triangle[i].size(); j++)
            {
                //just check which is minimum on next step of i and i+1 and add current element and store
                t[j]=min(t[j], t[j+1]) +triangle[i][j];
                
            }
        }
        return t[0];//return the first element which we will have answer
        
    }


    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &t)
    {
        
        //Base case
        //when we will reach the last index then return it value
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(t[i][j]!=-1)
            return t[i][j];
        //take the same index in next row
        int fs=triangle[i][j]+ solve(i+1, j, triangle,t);
        //take the j+1 index in next row
        int ss=triangle[i][j]+ solve(i+1, j+1, triangle,t);
        
        //return the minimum of both
        return t[i][j]=min(ss,fs);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    
//         //Recursion
        int m=triangle.size();//total row 
        int n=triangle[m-1].size();//max column
        
//         //Memoization
//         vector<vector<int>> t(m, vector<int> (n,-1));
//         return solve(0,0,triangle,t);
        
        //Tabulation approach
        
        vector<vector<int>> t(m, vector<int> (n,0));
        
        for(int i=0; i<n; i++)
            t[n-1][i]=triangle[n-1][i];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i ; j>=0; j--)
            {
                //compare with same index
                int fs=triangle[i][j] + t[i+1][j];
                //compare with next diagonal index
                int ss=triangle[i][j]+ t[i+1][j+1];
                //take minimum and store inside the current index
                t[i][j]=min(fs,ss);
            }
        }
        return t[0][0];
        
    }
