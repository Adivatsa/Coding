 void nextPermutation(vector<int>& nums) {
        
        //there is built in function in C++ STL
        //use next_permutation(start of array , end of array)
        //next_permutation(nums,nums + nums.size());
        
        //Method 1: Brute Force Approach
        //Take out all the permuatation and find out the next permutation of it
        //In this just return the next occured permuation
        //So total n! permuations will be there
        //TC=O(n!)xn where n is for compuation of n size array
        
        //Method 2:
        //Find the next largest element from n-1 to 1(sabse bada se next  chota wala) i.e index
        //if it has been not found that means all are in decreasing sequence
        //it is an edge case then just reverse it will be next permuatation
        //Now find out next greater element than next chota wala(index)uske right me
        //swap kar do dono ko
        //uske baad index ke aage wale sab reverse kar do
        
        //Algorithm
        //Step1: find a[i]<a[i+1] between 0 to n-2 for 0 indexing FROM reverse direction
        //if not found that means all are in decresing order then just sort the elemnets
        //Step2: Find any j for a[i]<a[j] 
        //Step3: swap a[i] & a[j]
        //Step4: Reverse the elements after i to last
        
        int n=nums.size();
        int i,j;
        //Step1: Find largest se next chota wala 
        for(i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
                break;      
        }
        
        if(i<0)//sab decresing order me hai
        {
            reverse(nums.begin() , nums.end());
        }
        else //STEP 2: find elemet greater than earlier found to his right only 
        {
            for(j=n-1;j>i; j--)
                if(nums[j]>nums[i])
                    break;
            
            //Step 3: swap both of them
            swap(nums[i], nums[j]);
        
            //reverse string after i to last
            reverse(nums.begin()+i+1,nums.end());
        }
    }