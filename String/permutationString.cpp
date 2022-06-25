    bool checkInclusion(string s1, string s2) {
        
        //Steps
        //Store s1 string inside one vector with there letter count
        //traverse s2 in form of window size equal to s1 length
        //store s2 window in vector with count and just compare s1 vector and s2 vector
        //if both are  equal means permuation are there
        
        vector<int> c1(26,0);
        
        for(auto it: s1)
        {
            c1[it-'a']++;
        
        }
        vector<int> c2(26,0);
        for(int i=0; i<s2.length(); i++)
        {
            c2[s2[i]-'a']++;
            if(i>=s1.length())
                c2[s2[i-s1.length()]-'a']--;
            if(c1==c2)
                return true;      
        }
        return false;
    }