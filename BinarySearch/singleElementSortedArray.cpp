    int singleNonDuplicate(vector<int>& nums) {
        
//         //Method 1: Using XOR operation
//         int ans=0;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             ans=ans^nums[i];
//         }
//         return ans;
//     }
    
    //Using Binary search
    //TC=O(logn) SC=O(1)
    //here with criteria than every num start with even index and add at even index
    //aftrt the single element it will chnge 
    //so based upon that criteria pass the end and start
    
    int s=0;
    int e=nums.size()-1;
    
    //Boundary checks
    if(e==0) //only one eleemnt is present
        return nums[e];
    else if(nums[e]!=nums[e-1])//last two elements are not equal
        return nums[e];
    else if(nums[0]!=nums[1])//starting both are not eqaul
        return nums[0];
        
    int mid;
    //Apply Binary search property
    while(s<=e)
    {
        mid= s+(e-s)/2;
        //Element found
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            return nums[mid];
        
        //if mid is found at even then go to search in right part else left part
        
        //Both are of true condition
        //check kar lo agr index even hai mid matlab next index same hona chahiye 
        //Check kar lo mid index odd hai toh pichla index equal hona chahiye
        //Both are true means this left part do not have single element as everyone at correct position so start ko aage badha do
        if((nums[mid]==nums[mid-1] && mid%2==1) ||(nums[mid]==nums[mid+1]  && mid%2==0))
            s=mid+1;
        else
            e=mid-1;
    }
    return -1;
    }