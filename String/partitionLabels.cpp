    vector<int> partitionLabels(string s) {
        
        // In this question we have to divide the string into max part such that
        //Any element should not occur in other part
        
        //Step1 : store the last occurance of every letter  inside map
        //Step 2: Take one start point and maximum length 
        //start point will be intially at before the first position of any part begin
        //maxi will get the max occurance of the letter
        //whenver index==maxi then it will be a part so store length inside vector
        
        unordered_map<char, int> m;
        vector<int> ans;
        for(int i=0; i<s.length(); i++)
            m[s[i]]=i;
        
        int spoint=-1;
        int maxi=INT_MIN;
        for(int i=0; i<s.length(); i++)
        {
            maxi=max(maxi, m[s[i]]);
            if(i==maxi)
            {
                ans.push_back(maxi-spoint);
                spoint=maxi;
            }
                
        }
        return ans;
        
    }