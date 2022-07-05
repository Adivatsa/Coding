    int longestConsecutive(vector<int>& nums) {
        
        //Brute Force Approach
        //TC=O(nlongn)
        //sort the given array and check for longest consecutive sequence
        
        //Optimised Approach TC=O(n) and SC=O(n)
        //take a set put all the elements inside it
        //iterate over nums vector and check if current element -1 present in set or not
        //if it is not present then check for curent eleement+1 and increase count
        //check for again current elemnrt+1 till it is not found
        //store max of count and ans variable
        
        unordered_set<int> s;
        //Insert all elements to set
        for(int it: nums)
            s.insert(it);
        for(auto it: s )
            cout<<it<<" ";
        int ans=0;
            
        //check for one by one for each element
        for(int i=0; i<nums.size(); i++)
        {
            int cnum=nums[i];
            int cnt=0;
            //check if current number -1 exists in set then do nothing otherwise
            //check for next number if found then  again check inc count
            if(s.find(cnum-1)==s.end())
            {
                //as cnt=0 so start from current number then go on increasing one by one
                while(s.find(cnum)!=s.end())
                {
                    //it means next current element +1 has been found in the set
                    //so increase count and check for next num
                    cnt++;
                    cnum++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }