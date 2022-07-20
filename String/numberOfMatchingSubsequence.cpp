    void solve(string &s, int i, unordered_map<string,int>&m, string &op, int & count)
    {
        if(i==s.length())
        {
            if(m.find(op)!=m.end())
            {
                count= count+m[op];
                m[op]--;
                cout<<op<<endl;
                cout<<m[op]<<endl;
                if(m[op]==0)
                    m.erase(op);
                
            }
                
            return ;
        }
        
        //pick the element
        op.push_back(s[i]);
        solve(s, i+1, m, op, count);
        op.pop_back();
        
        //Not pick the element
        solve(s, i+1, m, op, count);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        //Using Recursion: Brute force 
//         unordered_map<string, int> m;
//         for(int i=0; i<words.size(); i++)
//         {
//             m[words[i]]++;
//         }
//         for(auto it: m)
//             cout<<it.first<<" "<<it.second<<endl;
        
//         string op="";
//         int n=s.length();
//         int count=0;
//         solve(s,0,m,op,count);
//         return count;
        
        int n=s.length();
        unordered_map<char, vector<int>> m;
        //Store  the occurence of each character inside map with thier poisyion value
        for(int i=0; i<n; i++)
            m[s[i]].push_back(i);
        
        int ans=0;
        //Iterate overs the words vector
        for(int i=0; i<words.size(); i++)
        {
            //take the string from words vector
            string temp=words[i];
            //target will be specifiy that that index should be greater than target
            int target=-1;
            for(int j=0; j<temp.length(); j++)
            {
                //find index greater than target using upper bound function
                int index=upper_bound(m[temp[j]].begin(), m[temp[j]]. end(), target)- m[temp[j]].begin();
                
                //if index is larger than charcter vector then return false it is not possible
                if(index==m[temp[j]].size())
                    break;
                //otherwise update the target with ealier index inside map of vector
                target=m[temp[j]][index];
                //it means sequenc has been found so increment count
                if(j==temp.size()-1)
                    ans++;
            }
        }
        return ans;
    }