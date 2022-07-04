
    int candy(vector<int>& ratings) {
        
        //we have to give minimum candy to a single person
        //if rating is greater than neighbour then we have to give more candy to them
        //At first give one candy to each and iterate from left to right and store the candy distribution check if a[i+1]> a[i] then give more candy to i=1;
        //again from right calculate the cndy distribution if a[i]>a[i-1] then give more candy to i
        //for each rating of i take max of left and right
        
        int n=ratings.size();
        vector<int> left(n,1);
        
        //it will go from 1 to n-1 index 
        for(int i=1; i<n; i++)
        {
            if(ratings[i]> ratings[i-1])
                left[i]=left[i-1]+1;
        }
        for(auto it: left)
            cout<<it<<endl;
        //taking from right and comparing and updting inside left vector only
        int right=1;
        //it will got from n-2 index to 0
        for(int i=n-1; i>0; i--)
        {
            if(ratings[i]<ratings[i-1])
            {
                right++;
                left[i-1]=max(left[i-1], right);
            }
            else
                right=1;
        }
        for(auto it: left)
            cout<<it<<endl;
        
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=left[i];
        
        return sum;
    }