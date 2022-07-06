    int maxArea(vector<int>& height) {
        
        //Use of two pointer find the end indexs thiers distance
        //multiply with min water level and update the ans
        //which one is smaller increment that side and recalculate and update answer
        
        int ans=0;
        int i=0;
        int j=height.size()-1;

        
        while(i<j)
        {
            int temp=0;
            if(height[i]>=height[j])
            {
                
                temp=(j-i)*min(height[i], height[j]);
                j--;
            }
            else
            {
                
                temp=(j-i)*min(height[i], height[j]);
                i++;
            }
            ans=max(ans,temp);
        }
        return ans;
        
    }