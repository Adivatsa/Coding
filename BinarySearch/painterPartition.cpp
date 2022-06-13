bool ispossiblepaint(vector<int> boards, int k, int mid)
{
    int s=1;//Pianter count
    int currsum=0;
    for(int i=0; i<boards.size(); i++)
    {
        if(currsum+boards[i]<=mid)
        {
            currsum+=boards[i];
        }
        else
        {
            if(boards[i]<=mid)
            {
                currsum=boards[i];
                s++;
                if(s>k)
                    return false;
            }
            else
                return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //Similar to BOOk Allocation Problem

    int sum=0;
    for(int i=0; i<boards.size(); i++)
        sum+=boards[i];
    
    int s=0;
    int e=sum;
    int ans=-1;
    
    while(s<=e)
    {
        int mid= s+(e-s)/2;
        
        if(ispossiblepaint(boards,k,mid))
        {
            ans=mid;
            e=mid-1;
            
        }
        else
            s=mid+1;
            
    }
    return ans;
}