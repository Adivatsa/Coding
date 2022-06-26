    int romanToInt(string s) {
        //Store the mapping symbol to value inside the map
        //Result wuill be intialized to last character value;
        //Iterate from second last to first character
        //Check if value is less than next character then add to result
        //otherwise subtract from result
        
        //TC=O(n)
        //SC=O(1) duen ton only seven values has been added to map
        
        //Step1: Store inside the map
        
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        //Ste2: Store the last character value as a result
        int result=m[s[s.length()-1]];
        
        for(int i=s.length()-2; i>=0; i--)
        {
            //according to question in right side smaller value then add otherwise subtract from result
            if(m[s[i]]<m[s[i+1]])
                result= result-m[s[i]];
            else
               result= result+m[s[i]]; 
        }
        return result;
    }