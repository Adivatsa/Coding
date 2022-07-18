    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        //Number of rows
        int n=matrix.size();
        
        //Number of column
        int m=matrix[0].size();
        
        //Store the prefix sum
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                matrix[i][j]= matrix[i][j] + matrix[i][j-1];
            }
        }
        
        int count=0;
        unordered_map<int, int> mp;
        
        //take a window from colum to column
        for(int i=0; i<m; i++)
        {
            for(int j=i; j<m; j++)
            {
                //Apply logic of subarray sum to target k
                mp.clear();
                int sum=0;
                mp[0]=1;
                for(int row=0; row<n; row++)
                {
                    sum=sum+ matrix[row][j];
                    //taking all combinations to form prefix sum like columns 0 1 2 then at 2
                    //it will take 2 with 1 and 2 with 0 
                    if(i>0)
                        sum=sum-matrix[row][i-1];
                    if(mp.find(sum-target)!=mp.end())
                    {
                        count= count+mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return count;
        
    }