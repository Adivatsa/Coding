  int majorityElement(int a[], int size)
    {
        
        //In the question given that majority element is that occured more than n/2 times
        
        /*//Method 1: TC=O(nlogn) SC=O(1)
        //we will sort  the array and just compare based upon other elements
        //if equal then update cnt otherwise new element found so change count to 0
        if(size==1)
            return a[size-1];
        sort(a,a+size);
        int cnt=0;
        for(int i=1; i<size; i++)
        {
            if(a[i]==a[i-1])
            {
                cnt++;
                if(cnt==size/2)
                    return a[i];
            }
            else
            { 
                cnt=0;
            }
        }
        return -1;*/
        
        
        //Method 2: TC=O(n) and SC=O(1)
        //In this method is called as Moore Voting algorithm
        
        int majority;
        int cnt=0;
        for(int i=0; i<size; i++)
        {
            if(cnt==0)//it means koi new element ab majority bannega
            {
                majority=a[i];
                cnt++;
            }
            else if(a[i]==majority)
            {
                //majority is same as this element so update count
                cnt++;
            }
            else//element not same as majority element so decrement
                cnt--;
        }
        
        //Iterate over the array and find majority has count greater than n/2 times
        cnt=0;
        for(int i=0; i<size; i++)
        {
            if(a[i]==majority)
            {
                cnt++;
                if(cnt>(size/2))
                    return majority;
            }
        }
        return -1;
    }