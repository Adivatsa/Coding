class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
    
        //Subarray dia hai , window size dia hai 
        //toh sliding window use kar skate hai hum direct
        //main logic yeh rehta hai ki do variable lenge jo window ke start and end indicate karega
        //jab tk humara window k ke equal na ho jaaye tb tk shift karo end walo ko
        //sum bhi add karte raho
        //jaise he window ki size k ke equal ho jaaye tb tum uska sum ko max sum se compare kara lo
        //phir sum se ek aage ka hata lo aur start ko aage badha lo and end ko bhi 
        //so we will get new window of size k
        
        int i=0;//start
        int j=0;//end
        int sum=0;//sum nekalega poore window ka
        int maxSum=INT_MIN;
        
        while(j<N)//jab tk end array ke size se chota ho tab tk
        {
            //step 1: calculate sum
            sum=sum+ Arr[j];
            
            //step2: check if window size is k or not
            if(j-i+1 < K)//window ka size chota hai
            {
                j++;//end ko aage badha do
            }
            else if(j-i+1 == K)//agr window k ke equal hai toh
            {
                //maximum sum se compara kar lo
                maxSum=max(sum,maxSum);
                //aage se window badha do 
                sum=sum-Arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};