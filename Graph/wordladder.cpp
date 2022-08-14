    //to check the difference iterate over string and find the count
    int checkdifference(string a,string b)
    {
        int count=0;
        for(int i=0; i<a.length(); i++)
        {
            if(a[i]!=b[i])
                count++;
        }
        return count;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //inside the unorderd amp store the adjaceny list with only one letter difference
        unordered_map<string, vector<string>> m;
        for(int i=0; i<wordList.size(); i++)
        {
            for(int j=i+1; j<wordList.size(); j++)//start from next word 
            {
                if(checkdifference(wordList[i], wordList[j])==1)//check if only one ltter is different
                {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        //Storing the mapping for first word as it map be not presnt in vector string
        for(int i=0; i<wordList.size(); i++)
        {
            if(checkdifference(beginWord, wordList[i])==1)
            {
                m[beginWord].push_back(wordList[i]);
                m[wordList[i]].push_back(beginWord);
            }
        }
        
        //Apply BFS with string and height
        queue<pair<string, int>>q;
        //for visited used set 
        set<string> s;
        q.push({beginWord,1});
        
        while(!q.empty())
        {
            pair<string,int>p =q.front();
            q.pop();
            int height=p.second;
            //iterate over all the adjaceny list
            vector<string> str=m[p.first];
            for(auto it: str)
            {
                if(s.find(it)==s.end())
                {
                    q.push({it,height+1});
                    s.insert(it);
                }
                //if it is and enword then return ans
                if(it==endWord)
                    return height+1;
            }  
        }
        //not found
        return 0;  
    }