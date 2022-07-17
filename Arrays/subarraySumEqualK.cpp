    int subarraySum(vector<int>& nums, int k) {
        
        //Optimised Approach
        //TC=O(n) SC=O(n)
        //store the sum variable with thier count value as occurence
        //we will calculate sum everytime and check if sum-k present in map or not
        //if present increase count by its value and check sum is not presnt then insert 
        //otherwise increase sum value count in map by one
        unordered_map<int,int> m;
        int sum=0;
        m[0]=1;
        
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            //check if sum-k present in map or not
            if(m.find(sum-k)!=m.end())
                count=count+ m[sum-k];//present then add sum-k value to count
            m[sum]++;//increment sum value in map
        }
        return count;
        
    }