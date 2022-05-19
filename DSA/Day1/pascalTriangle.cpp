    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> v;

        //ek v type ka vector of vector banna lo
        for(int i=0; i<numRows; i++)
        {
            vector<int> ans(i+1,1);//ek vector bannao size+1 ka with all as 1
            for(int j=1; j<=i-1; j++)//go from 2nd to last-1
            {
                ans[j]= v[i-1][j] + v[i-1][j-1];//add the previous wala with both
            }
            v.push_back(ans); //usko main vector me push kar do
        }
        return v;  
    }