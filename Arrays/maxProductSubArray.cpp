    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        //Here main logic is similar to kaden's alg
        //we will take maxproduct till i and minproduct till i
        //for maxproduct we will comapre prev* nums[i], nums[i]
        //for minprodut will find maxmin till now
        //whenever we encounter any negative number will maxproduct, minproduct
        //so that negative number will be come to maxroduct and will be multiplied by maxproduct will +ve
        //At every iteration find the maximum of overall max, maxproduct
        
        //nums[i]: -2 3 -4
        //i:        0 1 S 2
        //minp:    -2-6 3 -12
        //maxp:    -2 3-6 24
        //Omax:    -2 3 3 24
        int currmaxproduct=nums[0];
        int maxproduct=nums[0];
        int currminproduct=nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]<0)
                swap(currmaxproduct, currminproduct);
            currmaxproduct= max(currmaxproduct* nums[i], nums[i]);
            currminproduct=min(currminproduct* nums[i], nums[i]);
            maxproduct=max(currmaxproduct, maxproduct);
        }
        return maxproduct;
    }