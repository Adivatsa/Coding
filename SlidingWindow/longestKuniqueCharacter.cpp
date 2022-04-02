class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        //In brute force method we can just find out all substring and count no of unique characters
        //Which substring that has K unique charcters then just store its length
        //Find out the max of length and return it
        //TC=O(n^2)
        
        //Better Approach
        //Sliding window method TC=O(n)
        //Main logic yeh rahega yaha pe ki ek map create kar lo
        //map is kyu liya as humme pata hai duplicate store nai hga
        //jab bhi koi elelmet aayega check kar lo map me hai toh uska count badha do
        //Warna create kar do value me 1 daal do
        //Agr map ka size K ke equal ho jaaye matkb K unique characters then just find window size
        //compare max length with curr length if greater update it
        //Jab bhi map size K sw jyada hga toh aage se element delete kara do
        //count ko decrese kara do map me se if count==0 ho jaaye toh map se erase kar do
        //last me max length ko return kara do
        
        int maxLen=-1;//return -1 if nothing present
        int i=0;//Start point
        int j=0;//End point
        unordered_map<char,int> m;
        int n=s.length();
        
        while(j<n)
        {
            //Step1: check present in map if yes increase its count value otherwise store and increase
            m[s[j]]++;
            
            //step2: check if unique characters are less than k then add more
            if(m.size() < k)
                j++;
            else if(m.size() == k)//if map size is same as unique characters then store max length
            {
                maxLen=max(maxLen, j-i+1);
                j++;
            }
            else if(m.size() > k)
            {
                //if map size is greater than just decrese the size
                //delete from map if count value is 0
                while(m.size() > k)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
        
        
    }
};