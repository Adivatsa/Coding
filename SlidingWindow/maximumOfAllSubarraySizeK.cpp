class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        //Ish question me humme toh har ek K size ke window ka max nekalna hai
        //Brute force me ek loop i se i+k tk phir uska max nekal lo
        //and aise he sabka nekal lo phir ek vector ya list me store kara lo
        //Now using optimisation by sliding window
        //Main logic yeh ki har ek window ka max nekal lenge aur slide kar dnge window
        //Isme main problem yeh hgi ki slide karte time max wala he window se bahr ho jaye
        //toh ushe chota humme chahiye hga 
        //Isliye ek list banna lo jiska front hamesha max dega 
        //Agr koi bhi element max ke left side me hai aur chota hai wo delte maar do list se kyuki wo kabhi use nai hga 
        //kyuki list me yeh max wala last tk rahega 
        //jitne bhi right me hnge unhe store kara lo chota wala kyuki agr max wala window se hatega toh nxt whi max bnega
        
        int i=0;//start
        int j=0;//end
        
        list<int> l;//Maximum ka track rakhne ke liye
        vector<int> v;//yeh max store karega 
        
        while(j<n)
        {
            
            //step 1: Isme calculation karo
            //koi bhi element aya check kar lo agr list me ushe chota element hai toh delete kar do
            //aur list empty na ho 
            //phir push maar do list me as a potential maximum 
            //sidhi baat hai jo bhi element insert hga uske left side ke saare chote ko delete kar do but right wale rahenge
            //kyuki yeh jab window se bahr hga toh whi right ke chote wale ho sake toh ush window ke max hnge
            while(l.size()>0 && l.back()<arr[j])
                    l.pop_back();
            
            //add kar do list me
            l.push_back(arr[j]);
            
            //step2: if less than k window increase j
            if(j-i+1 < k)
            {
                j++;
                
            }
            else if(j-i+1 == k)
            {
                //phle ans store kara lo
                //front wala he max hga list me
                v.push_back(l.front());
                
                //slide the window
                //Agr phla element he max hai toh list se bhi delete karo
                if(arr[i] == l.front())
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
        
    }
};