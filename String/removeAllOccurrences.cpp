    string removeOccurrences(string s, string part) {
        //find function will find out the first ocuurance of any string
        //we will iterate till length not become 0
        //find out the the first ocuurence of part string
        //then erase it from the main string
        //erase function will erase from start iterator and lem it will require
        //here it will erase(starting of part , length of part)
        int n=s.length();
        int m=part.length();
        
        while(n!=0 && s.find(part)<n)
        {
            s.erase(s.find(part),m);
        }
        return s;
    }