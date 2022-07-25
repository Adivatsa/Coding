    int getMaxLen(vector<int>& nums) {
        
        int n=nums.size();
        
        int len=0;
        int start=0;
        while(start<n)
        {
            int i=start;
            //Skipping all the zero's in starting
            while(i<n && nums[i]==0)
                i++;
            
            //All Zeros ahs been  removed
            int j=i;
            //Count number of negative numbers
            int ncnt=0;
            //first negative number index
            int nfrst=-1;
            //last negative number index
            int nlst=-1;
            
            while(j<n && nums[j]!=0)
            {
                if(nums[j]<0)
                {
                    ncnt++;
                    if(nfrst==-1)
                        nfrst=j;
                    
                    nlst=j;
                }
                j++;
            }
            
            //there are two cases it may possible again 0 encountered
            //otherwise it has reached to end
            //find ans with all two condition
            //first if even number of negatives
            if(ncnt%2==0)
            {
                len=max(len, j-i);
            }
            else//odd number of negative
            {
                //skip first and find length
                if(nfrst!=-1)
                    len=max(len,j-nfrst-1);
                
                //skip last and find length
                if(nlst!=-1)
                    len=max(len, nlst-i);
            }
            start=j;
            
        }
        return len;
    }