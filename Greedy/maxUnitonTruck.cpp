    static bool comp(vector<int>&v1, vector<int>&v2)
    {
        if(v1[1]>v2[1])
            return true;
        else
            return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //sort according to units
        //chck with currsize less than truck size then update it
        //an add to unit*box number to ans
        //return ans
        sort(boxTypes.begin(), boxTypes.end(),comp);
        int ans=0;
        int currsize=0;
        for(int i=0; i<boxTypes.size(); i++)
        {
            int nbox=boxTypes[i][0];
            int unit=boxTypes[i][1];
            if(currsize+nbox<=truckSize)
            {
                ans=ans+(nbox*unit);
                currsize+=nbox;
            }
            else if(currsize<truckSize)
            {
                int diff=truckSize-currsize;
                ans+=diff*unit;
                currsize=currsize+diff;
            }
        }
        return ans;
    }