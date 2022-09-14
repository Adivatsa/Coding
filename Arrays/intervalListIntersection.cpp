    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<secondList.size())
        {
            //first index will be max of first index from both
            //Second index will be from min of second index
            int first=max(firstList[i][0], secondList[j][0]);
            int second=min(firstList[i][1], secondList[j][1]);
            //whenever second is greater than it had matching portion
            if(first<=second)
                ans.push_back({first,second});
            
            //if second list end is greater then increase 1st list pointer
            if(firstList[i][1]< secondList[j][1])
                i++;
            else//else do not increase the pointer
                j++;
        }
        return ans;
    }