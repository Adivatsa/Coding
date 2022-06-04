    int findDuplicate(vector<int>& nums) {
        


        
//         //using linked list with slow and fast pointer and Cycle Detection
        
//         int slow=nums[0];
//         int fast=nums[0];
        
//         do
//         {
//             fast=nums[nums[fast]];
//             slow=nums[slow];
            
//         }while(slow!=fast);
//         fast=nums[0];
//         while(slow!=fast)
//         {
//             fast=nums[fast];
//             slow=nums[slow];
            
//         }
        
        
        
//         return slow;
        

//     int n=nums.size()-1;
//     int low=1;
//     int high=n;
//     int mid;
//     while(low<high){
//         mid=(low+high)/2;
//         int count=0;
//         for(int num:nums){
//             if(num<=mid) count++;
//         }
//         if(count>mid) high=mid;
//         else low=mid+1; 
//     }
//     return low;

        //Using hash map Approach
        int n=nums.size();
        unordered_map<int,int>m;
        int temp;
        
        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                temp= nums[i];
                break;
            }
        }
        return temp;
        
  
    }