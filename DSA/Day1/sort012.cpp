void sortColors(vector<int>& nums) {
        
        int i=0;// i will match 0
        int j=0;//j will match 1
        int k=nums.size()-1;//k will match for 2
        
        while(k>=j)//jab tak j bada na ho jaaye k se 
        {
            if(nums[i]==0)//i sahi position pe hai 
            {
                i++;
                j++;
            }
            else if(nums[j]==1)//j sahi position pe hai
                j++;
            else if(nums[k]==2)//k sahi position pe hai
                k--;
            else if(nums[i]==1 && nums[j]==0)//i and j at opposite position
            {
                swap(nums[i],nums[j]);//sahi position pe aa gya
                i++;
                j++;
            }
            else if(nums[j]==2 && nums[k]==0)//k ke jagh pe 2 hai
            {
                swap(nums[j], nums[k]);//k sahi jgh pahuch gya
                k--;
                
            }
            else if(nums[j]==2 && nums[k]==1)//k and j ke jgh opposite hai
            {
                swap(nums[j],nums[k]);//dono sahi jgh pahuch gye hai
                k--;
                j++;
            }
        }
        
    }