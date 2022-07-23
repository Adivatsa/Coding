//     static bool comp(string &s1, string &s2)
//     {
//         if(s1.length()<s2.length())
//             return true;
//         else
//             return false;
//     }
//     int longestStrChain(vector<string>& words) {
        
//         //map will have string with count value
//         //for derived count will increase like if bda da=2 is there then bda=3
//         //if bda ba not present then ba=0 and bda=1 that we dont want
//         unordered_map<string,int>m;
//         //Sort acording to length of it
//         sort(words.begin(),words.end(),comp);
//         int ans=0;
        
//         //iterate over each word present inside vector
//         for(auto w:words)
//         {
//             for(int i=0; i<w.length(); i++)
//             {
//                 //remove one by one each element and see inside the map
//                 string temp= w.substr(0,i)+w.substr(i+1);
//                 //It may be possible that this string has been occured for the first time
//                 //so that count will  be 0 as first so that max with word and temp string +1
//                 m[w]=max(m[w], m[temp]+1 );
//             }
//             ans=max(ans,m[w]);
//         }
//         return ans;
//     }
    
    //2nd Method using DP of Lis Variation
    bool checkEqual(string &s1, string &s2)
    {
        //s1 string is big and s2 is small
        //if length differ more than 1 return false
        if(s1.length()!=s2.length()+1)
            return false;
        
        int i=0;//for first string
        int j=0;//second string
        while(i<s1.length())
        {
            if(j<s2.length() && s1[i]==s2[j])//if both matched
            {
                i++;
                j++;
            }
            else//not matched only increment for first string
                i++;
        }
        //Both string has reached to the last
        if(i==s1.length() && j==s2.length())
            return true;
        else
            return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.length()< s2.length();
    }
    int longestStrChain(vector<string>& words) {
        
        //sort according to the length
        sort(words.begin(), words.end(), comp);
         
        int n=words.size(); 
        vector<int> t(n,1);
        int maxi=1;
        //Lis code
        
        for(int index=0; index<n;index++)
        {
            for(int pindex=0; pindex<index; pindex++)
            {
                if(checkEqual(words[index],words[pindex]) && t[pindex]+1 > t[index])
                {
                    //check condition is there to check if both are equal and one has one more character in it
                    t[index]= t[pindex]+1;
                }
                if(t[index]> maxi)
                {
                    maxi=t[index];
                }
            }
        }
        return maxi;
    }
    