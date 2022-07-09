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