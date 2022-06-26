int findSubString(string str)
    {
        //Steps
        //Push all the characters into set get the count the unique characters
        //create a map and start putting the string into map and increament the cnt value
        //whenver cnt reaches size of set then
        //take one pointer start decrementing cnt in map till cnt >1
        //update the ans with minimum length
        
        set<char> s;
        for(auto it: str)
            s.insert(it);
            
        int i=0;
        int j=0;
        //n will contain all unique character length
        int n=s.size();
        //map will store character and its count
        unordered_map<char,int> m;
        int ans=str.length();//Worst case ans will be whole string
        while(i<str.length())
        {
            m[str[i]]++;
            
            //just if map size is equal to set size
            if(m.size()==n)
            {
                //if equal then start removing elements from front side till 
                //Till character count in map is greater than 1
                while(m[str[j]]>1)
                {
                    m[str[j]]--;
                    j++;
                }
                //Store the ans of it
                ans=min(ans,i-j+1);
            }
            i++;
        }
            
        return ans;    
    }