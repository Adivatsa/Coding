    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //Alg
        //1. if interval is not sorted just sort it
        //2. Check if current interval <=previous interval then include it
        
        
        vector<vector<int>> ans;
        
        int n=intervals.size();
        //sort according to start time
        sort(intervals.begin(), intervals.end());
        
        for(int i=0; i<n; i++)
        {
            if(ans.size()==0)
            {
                //first interval arrived
                ans.push_back(intervals[i]);
            }
            else
            {
                //Reference as changes will be reflected
                vector<int>& prev=ans.back();//last wale interval stored ko prev vector me daal lo
                
                //check if current start is less than prev end then include it
                //interval[i][0]=start time
                //interval[i][1]=end time
                //prev[1]=end time
                if(intervals[i][0]<=prev[1])
                {
                    //then include it
                    prev[1]=max(intervals[i][1], prev[1]);//which one last is grater
                }
                else
                {
                    //Not include it
                    ans.push_back(intervals[i]);
                }
            }
        } 
        return ans;  
    }