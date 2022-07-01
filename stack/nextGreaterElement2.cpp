    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> v;
        stack<int> s;
        //for circular we can use any element from nusm vector 
        //store all elements into stack 
        //then find next greater to right 
        for(int i=nums.size()-1; i>=0; i--)
                s.push(nums[i]);
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            
             if(s.empty())
            {
                v.push_back(-1);
            }
            else if(s.size()>0 && nums[i]<s.top())
            {
                v.push_back(s.top());
            }
            else if(s.size()>0 && nums[i]>=s.top())
            {
                while(s.size()>0 && nums[i]>=s.top())
                    s.pop();
                if(s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i]);
        }
          reverse(v.begin(), v.end());
        return v;
    }