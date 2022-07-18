    string getHint(string secret, string guess) {
        
        int bulls=0;
        int cows=0;
        //Map will store values which are not matched in guess string
        unordered_map<char,int> m;
        for(int i=0; i<secret.length(); i++)
        {
            if(secret[i]==guess[i])//it has been matched at correct position that is bull
                bulls++;
            else
                m[secret[i]]++;;       
        }

        for(int i=0; i<guess.length(); i++)
        {
            //if not matched with secret and found in map then can be used as cow and decrement count , if count is 0 then erase from map
            if(secret[i]!=guess[i] && (m.find(guess[i])!=m.end()))
            {
                cows++;
                m[guess[i]]--;
                if(m[guess[i]]==0)
                    m.erase(guess[i]);
            }      
        }
        
        string op="";
        op=to_string(bulls)+"A"+to_string(cows)+"B";
        return op;
        
    }