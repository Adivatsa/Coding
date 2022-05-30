    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Smallest has been asked so go for max heap store till k 
        //if size>k just pop it
        //at last return the top of the heap

        //STL to max heap
        priority_queue<int> p;
        int n=matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                p.push(matrix[i][j]);
                if(p.size()>k)
                    p.pop();
            }
        }
       return p.top(); 
        
    }