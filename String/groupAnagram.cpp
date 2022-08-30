    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //Steps:
        //we will sort everytime and push into map corresponding same value
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(auto s: strs)
        {
            string t=s;
            //sort it
            sort(t.begin(), t.end());
            //push into map
            m[t].push_back(s);  
        }
        for(auto it: m)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }