    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        //sort the special floors
        sort(special.begin(), special.end());
        //take one ans variable to store maximum consecutiva floors
        int ans=0;
        //Storing consecutive floors between to special floors
        for(int i=0; i<special.size()-1; i++) 
            ans=max(ans,special[i+1]-special[i]-1);
        
        //Consecutive floors between bottom to first special floor
        ans=max(ans,special[0]-bottom);
        //Consecutive floors between top to last special floor
        ans=max(ans,top-special[special.size()-1]);
        //return max consecutive floor
        return ans;
    }