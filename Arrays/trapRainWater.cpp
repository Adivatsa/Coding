class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
      /*  //Method 1: TC= O(n) && SC=O(n) due to making two array we can optimise using two pointer approach
        //Base case
        if(n<2)
            return 0;
        //2 array maintain karenge one is for left maximum and other is for right maximum
        //ans neakl ke ek avriable me store karte jaayenge
        //find the max left array for each block where start index will have 0 
        //first assign then comapre if graeter then update
        
        long long int leftar[n],rightar[n];
        
        //for left max
        leftar[0]=0;
        int leftmax=arr[0];
        for(int i=1; i<n; i++)
        {
            leftar[i]=leftmax;
            leftmax=max(leftmax , arr[i]);
        }
        
        //for right amx array
        rightar[n-1]=0;
        int rightmax=arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            rightar[i]=rightmax;
            rightmax=max(rightmax,arr[i]);
        }
        
        //Now finding how much water has been trapped
        //trap will min(left,right)-ush block ki height;
        //for first and last trap will be always zero
        
        long long trapwater=0;
        
        for(int i=1; i<n-1; i++)
        {
            if(leftar[i]> arr[i] && rightar[i]>arr[i])
            {
                int temp= min(leftar[i],rightar[i])-arr[i];
                trapwater=trapwater + temp;
            }
            
        }
        return trapwater;*/
        
        //Method 2: Using double pointer approach as TC=O(n) && SC=O(1)
        //main logic yeh hai ki jis side ki pointer ke value choti hgi ush side continue hga
        //for every element it will check agr height choti hai max se toh water store hga otherwise nai hga
        //Ni hga ush case me hum bs update kar dnge max ko 
        
        //2 pointer banna lo first last element kabhi water store nai karenge
        int l=1;
        int r=n-2;
        int leftmax=arr[0];
        int rightmax=arr[n-1];
        long long trapwater=0;
        //jab tk left pointer right se aage na chal jaaye we will execute
        while(l<=r)
        {
            //condition check kar lo jo height chota hga ush side start karenge
            //Because yeh ho sakta hai agr bada height se start kare toh dhushree side height 0 ho
            //then we can't  store water in this scenario
            
            if(leftmax <= rightmax )
            {
                //matlb left wala height chota hai
                if(arr[l]>=leftmax)
                {
                    //water store nai hga
                    leftmax=arr[l];
                }
                else
                {
                    //it can store water
                    trapwater= trapwater +leftmax-arr[l];
                }
                //update kar do left ko
                l++;
            }
            else
            {
                //matlb right wala height chota hai
                if(arr[r]>=rightmax)
                {
                    //water store nai hga
                    rightmax=arr[r];
                }
                else
                {
                    //it can store water
                    trapwater= trapwater +rightmax-arr[r];
                }
                r--;
            }
        }
        return trapwater;
    }
};