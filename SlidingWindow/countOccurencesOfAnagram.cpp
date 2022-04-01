class Solution{
public:
	int search(string pat, string txt) {
	    
	    //Sliding window method
	    //Main logic here is we have to count the occurences of anagram
	    //Anagram length is fixed so it can be considered as window size
	    //Now we are searching substring type so it will be same letter but jumbled
	    //TAKE one variable count which will have value as number of distinct letters
	    //Create a map with all occurences of distinct letters
	    //Check for every window if found decrement it
	    //If anyone has value to 0 then decrement count value
	    //For result just check count is 0 or not if yes then increment your occcurence
	    
	    int i=0;//start
	    int j=0;//end
	    unordered_map<char,int>m;//to store count of pattern string;
	    //Total distinct letters in pattern
	    int ans=0;
	    int n=txt.length();
	    int p=pat.length();
	    //storing the count of letters in map
	    for(int k=0;k< p;k++)
	    {
	            m[pat[k]]++;
	    }
	    //anagramCount will store number of distinct letters in pattern
	    int anagramCount=m.size();
	    while(j<n)
	    {
	        //step 1: just decrement the count value in map
	        //check if that letter count is 0 then decrement unique value
	        if(m.find(txt[j])!=m.end())
	        {
	            m[txt[j]]--;
	       
	       //check for count reches to zero or not if yes decrement anagramcount
	            if(m[txt[j]]==0)
	                anagramCount--;
	        }
	            
	            
	       //Step2: if window size is small then increment j value
	       if(j-i+1 < p)
	            j++;
	       
	       //Step3: If window is same then caluate ans and slide window
	       else if(j-i+1 ==p)
	       {
	           //calculate ans
	           if(anagramCount==0)
	                ans++;
	           
	           //Slide the window
	           //check akr lo agr uska count 0 hai toh phle unique increment kar do
	           
	           if(m.find(txt[i])!=m.end())
	           {
	               //phir map me value incement kar do 
	               m[txt[i]]++;
	               if(m[txt[i]]==1)//check kar locount 1 means phle 0 hga so anagram ko increment kar do
	                    anagramCount++;
	           }
	            
	           
	           
	           i++;
	           j++;
	           
	           
	       }
	    }
	    return ans;
	}

};