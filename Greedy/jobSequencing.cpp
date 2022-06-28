class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //Step 1: sort the array according to profit
        //step2: find the maximum deadline
        //step 3: create the deadline array from 1 to max deadline and assign -1 to it
        //Step 4: start iterating from each jobs array
        //find each deadline from last to greater than 0 in array
        //if any place is -1 then put the job and increase maxprofit and job cnt 
        //Return at last maxprofit and job count
        
        //sorting according to profit 
        sort(arr,arr+n,comp);
        
        //Finding the maximum daeadlinr
        int maxi=arr[0].dead;
        for(int i=1; i<n; i++)
            maxi=max(maxi, arr[i].dead);
         
        //array creation  to store which jon has been done at start all as -1   
        int jdone[maxi+1];
        for(int i=1; i<=maxi; i++)
            jdone[i]=-1;
        
        //Maximum profit and job count will be stored 
        int maxprofit=0;
        int jobcnt=0;
        
        //Traverse for each Jobs which has been given
        for(int i=0; i<n; i++)
        {
            //starting assigning jobs to thier deadlines and then shifting to left
            for(int j=arr[i].dead; j>0; j--)
            {
                //It means no job has been assigned here so assign job
                //Add the profit and Job count and break so that go to next job
                if(jdone[j]==-1)
                {
                    jdone[j]=arr[i].id;
                    maxprofit+=arr[i].profit;
                    jobcnt++;
                    break;
                }
            }
        }
        //Store in vector in the form first profit and then job count , return vector
        vector<int> ans;
        ans.push_back(jobcnt);
        ans.push_back(maxprofit);
        return ans;
    } 
};