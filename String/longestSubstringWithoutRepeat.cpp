    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==1)
            return 1;
        unordered_map<char, int> m;
        int i=0;
        int j=0;
        int maxi=0;
        while(i<s.length())
        {
            m[s[i]]++;
            while(m[s[i]]>1)
            {
                m[s[j]]--;
                j++;
            }
            maxi=max(maxi, i-j+1);
            i++;
        }

        return maxi;
    }