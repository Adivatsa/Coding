    vector<int> searchRange(vector<int>& nums, int target) {
        
    int n=nums.size();
    //In this wwe have to find first and last occurence of a key value
    //for the first occurance if got key at mid go to left side by decrement end
    //for the last occurance if got key then store go towards right side with increase start
    
    vector<int> ans;
    
    int s=0;
    int e=n-1;
    int temp=-1;
    int mid;
    //first occurance
    while(s<=e)
    {
        mid=s+(e-s)/2;
        //It has been found so store and go left it may be possible chota index pe aur bhi ho
        if(nums[mid]==target)
        {
            temp=mid;
            e=mid-1;
        }
        else if(nums[mid]>target)
            e=mid-1;
        else
            s=mid+1;
    }
    
    ans.push_back(temp);
    
    mid=0;
    s=0;
    e=n-1;
    //last occurance
    int temp2=-1;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        //It has been found so store the index and go to right to see if target exists in right side
        if(nums[mid]==target)
        {
            temp2=mid;
            s=mid+1;
        }
        else if(nums[mid]>target)
            e=mid-1;
        else
            s=mid+1;
    }
    
    ans.push_back(temp2);
    
    return ans;
        
    }