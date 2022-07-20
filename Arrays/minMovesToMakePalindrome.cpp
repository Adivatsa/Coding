    int minMovesToMakePalindrome(string s) {
        
        //Using Two pointer Approach
        
        int n= s.length();
        int left=0;
        int right=n-1;
        
        
        int count=0;
        while(left<right)
        {
            //left and right will be boundary and we will iterate through i and j pointer
            int i=left, j=right;
            //check if there are different
            while(s[i]!=s[j])
                j--;
            
            //it would be at last position or at in middle 
            if(i==j)
            {
               //found at very first position at left then do not decrement
                swap(s[j], s[j+1]);
                count++;
                continue;
            }
            else
            {
                //It has been found in middle take it to required position
                //swap till and take it to the right position
                while(j<right)
                {
                    swap(s[j], s[j+1]);
                    count++;
                    j++;
                }
            }
            left++;
            right--;
        }
       return count; 
    }