bool pagealloc(int A[], int N, int M,int mid)
    {
        //try to assign pages to students 
        //if it exceeds no of students and pages remaining
        //return false
        int s=1;//For students
        int currsum=0;
        for(int i=0; i<N; i++)
        {
            if(currsum+A[i]<=mid)
            {
                currsum+=A[i];
            }
            else
            {
                //Check page should be less than mid 
                //increase student count and assign new fresh currsum to it
                //once check student count if greater than M then return false;
                if(A[i]<=mid)
                {
                    s++;
                    currsum=A[i];
                    if(s>M)
                        return false;
                }
                else
                    return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //Here the number of pages is N 
        //Number of students is M 
        //We have to find minimum of maximum pages allocated
        //First we will find max for each iteration we will store ans and go for min
        //Search space will be limited to 0 to tatal pages
        //if all pages has been assigned to M students then find min so go left side on search space
        
        int sum=0;
        for(int i=0; i<N; i++)
            sum+=A[i];
            
        //Define the search space
        int l=0;
        int h=sum;
        int ans=-1;
        while(l<=h)
        {
            //if books will be allocated then store ans and find min
            //otherwise minimise search space to get allocated
            
            int mid=l+(h-l)/2;
            
            if(pagealloc(A,N,M,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }