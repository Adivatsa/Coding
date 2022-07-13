    //Optimised Approach    #TC=O(log(min(n1,n2)))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //Optimal Solution  #TC=O(min(n1,n2))
        //we will Apply binary search on smaller array to reduce the complexity
        
        //which is smaller make it as a first array
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        int s=0;
        int e=n1;
        //Apply Binary Search
        while(s<=e)
        {
            //Find mid of nums1 array
            int mid1=s+(e-s)/2;

            //middle of nums array 2 will be total length/2 -mid1
            int mid2=((n1+n2+1)/2)-mid1;  //1 is added to have odd case where  first group have one extra element

            //assigning the boundaries
            int left1, left2, right1, right2;

            //left will contain minimum and right will be have max element
            
            //if cut is at 0 so num1 has 0 elemnts so assign left as -infinty 
            if(mid1==0)
                left1=INT_MIN;
            else
                left1=nums1[mid1-1];

            if(mid2==0)
                left2=INT_MIN;
            else
                left2=nums2[mid2-1];
            
            //every element has been taken then right will maximum +infinity
            if(mid1==n1)
                right1=INT_MAX;
            else
                right1=nums1[mid1];

            if(mid2==n2)
                right2=INT_MAX;
            else
                right2=nums2[mid2];

            //if l1<=r2 and l2<=r1 then return meadin for even length as max(l1,l2)+min(r1,r2)/2 
            //for odd length median lies as max(l1,l2)
            
            if(left1<=right2 && left2<=right1)
            {
                //if even return meadin for even length as max(l1,l2)+min(r1,r2)/2
                if((n1+n2)%2==0)
                    return (max(left1, left2)+ min(right1, right2))/2.0;
                else//for odd length median lies as max(l1,l2)
                    return max(left1, left2);
            }
            if(left1>right2)//if first array division contain greater than second right element then move left
                e=mid1-1;
            else
                s=mid1+1;
        }
        //we have to return something
        return 0.0;
    }