    static bool comp(string &s1, string &s2)
    {
        if(s1.length()<s2.length())
            return true;
        else
            return false;
    }
    int longestStrChain(vector<string>& words) {
        
        //map will have string with count value
        //for derived count will increase like if bda da=2 is there then bda=3
        //if bda ba not present then ba=0 and bda=1 that we dont want
        unordered_map<string,int>m;
        //Sort acording to length of it
        sort(words.begin(),words.end(),comp);
        int ans=0;
        
        //iterate over each word present inside vector
        for(auto w:words)
        {
            for(int i=0; i<w.length(); i++)
            {
                //remove one by one each element and see inside the map
                string temp= w.substr(0,i)+w.substr(i+1);
                //It amy be possible that this string has been occured for the first time
                //so that count will  be 0 as first so that max with word and temp string +1
                m[w]=max(m[w], m[temp]+1 );
            }
            ans=max(ans,m[w]);
        }
        return ans;
    }