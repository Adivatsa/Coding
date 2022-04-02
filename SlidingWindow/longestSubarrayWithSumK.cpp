class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        /*
        // Method1: Only applicable to positive number array
        //yaha pe sliding window ke concept ko use karenge
        //if sum is less than k then increase end pointer matlb window ko bada karo
        //if sum is equal to k then find maximum of current window size and maximum stored
        //if sum is greater than k then increse first pointer till sum less than or equal to k
        
        int i=0;//start point
        int j=0;//end point
        int maxLen=INT_MIN;
        int sum=0;//track the sum value
        
        while(j<N)
        {
            //step1: add the element to sum
            sum=sum+ A[j];
            
            //Step2: check if sum is less than k increase end pointer
            if(sum<K)
                j++;
            
            //Step3: check if sum equal to k then store the max of current max vs older max
            else if(sum==K)
            {
                maxLen=max(maxLen, j-i+1);
                j++;
            }//step4: if sum greater than k then just remove elements from start till sum less or equal to k
            else if(sum>K)
            {
                while(sum>K)//Remove jab tk sum less or eqaul na ho jaaye
                {
                    sum=sum-A[i];
                    i++;
                }
                
                j++;
            }
            
        }
        return maxLen;*/
        
        //Method2: Using maps which will applicable to both positive and negative number
        //here main logic is we will find sum 
        //if sum is less than k then increase window size and add sum again
        //if sum is equal to k then we will store the maximum length
        //Map ka use karenge yaha pe
        //0 ko daal do with index as 0 bcz if sum=k then sum-k will search 0 only
        //Agr wo element first time aayega toh map me daal dnge with index as value
        //phir check akr lenge sum-k hai kya map me if available then 
        //apne index se ush sum-k ke index ko subtact kara lo waha pe subarray aa jaayega
        //mann lo ki sum aaya at i, search sum-k wo aaya j pe then sum=k milega j-i+1 pe 
        //yhi logic use karenge
        
        //DRY RUN IT IT IS VERY EASY
        unordered_map<int,int> m;
        int maxLen=0;
        int sum=0;
        
        m[0]=0;//yeh check kar lega agr same K melega toh k-k=0 hga toh uska answer de dega
        for(int i=0; i<N ; i++)
        {
           sum=sum+ A[i];
           if(m.find(sum)==m.end())//map me daal do agr nai toh
            {
                m[sum]=i+1;//0 pe 0 daala hai so 1 increase karke daalo
            }
            if(m.find(sum-K) != m.end())
            {
                //Search kar lo sum-k 
                //if present then update max len
                maxLen=max(maxLen, i-m[sum-K]+1);//len=end-start+1 then i-len then cmp max
            }
        }
        return maxLen;
    } 

};