    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        
        //Steps
        //we will have relation between each diagonal as i-j will be same for same diagonal
        //we will store in map with difference of i-j and values as min heap
        //take out element form min heap and pusg into matrix
        
        unordered_map<int, priority_queue<int, vector<int> ,greater<int>>>m;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                m[i-j].push(mat[i][j]);//store in map with min heap
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                mat[i][j]=m[i-j].top();//put element from min heap top
                m[i-j].pop();//pop from that map location
            }
        }
        return mat;
        
    }