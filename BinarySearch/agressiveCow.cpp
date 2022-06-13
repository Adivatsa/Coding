bool ispossible(vector<int> &stalls, int k, int mid)
{
    int cow=1;//store cow count with intial only one cow
    //intial first cow will be placed at first position
    int distance=stalls[0];
    //iteate over distance vector put all other cows
    for(int i=0; i<stalls.size(); i++)
    {
        //Check if distance id grater than or equal to mid then we can place the cow at that place
        //To place the cow increase cow count and find it should eqal than given cow count then all count has been placed
        //update distance to that place so next cow will ve from that distance
        if(stalls[i]-distance>= mid)
        {
            cow++;
            if(cow==k) return true;
            distance=stalls[i];
        }
    }
    //It means cow are remaining and all has been not been placed
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s=0;
    //For storing the max distance
    int maximum=-1;
    //for(int i=0; i<stalls.size(); i++)
        	//maximum=max(stalls[i],maximum);
    int e=stalls[stalls.size()-1];
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        //check if at distance of mid can we place cows
        if(ispossible(stalls, k,mid))
        {
            ans=mid;//store aand find max distance should be placed cow to avoid fight
            s=mid+1;//go to write side we want maximum distance
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}