    bool isSubsetSum(vector<int>arr, int sum){
        
        //Yeh problem kehta hai ki sum ke equal koi bhi subset hai kya array me
        //This is related to 0-1 kanapsack problem
        //Similar like weight array here array of integers given
        //Instead of kanapsack capacity here sum has been given
        //val array of kanapsack has been ignored
        //intialization will be in the form of true and false
        
        //take a matrix of size array size and sum t[arr.size+1][sum+1]
        //now for intilaziation purpose if array is given but sum is 0 then true it will be
        //if array has 0 elements and required sum is 1,2...sum then false
        
        //Approach yeh hai ki agar sum se chota hai usko include kare ya nai 
        //agr include karenge toh true hga warna false hga
        //Agr sum se jyada ho gya toh wo subset nai hga so false
        //last corner will give if any subset is present or not
        
        //TC=O(n* sum)  SC=O(n*sum)
        bool t[102][10002];
        int n=arr.size();
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                //step 1 : intialization
                if(i==0)//array size is 0 but sum is more than 0 which is impossible
                    t[i][j]=false;
                if(j==0)//sum is 0
                    t[i][j]=true;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                /*//step 1 : intialization
                if(i==0)//array size is 0 but sum is more than 0 which is impossible
                    t[i][j]=false;
                else if(j==0)//sum is 0
                    t[i][j]=true;*/
               if(arr[i-1] <= j)//subset jo hai sum se chota hai & decide to include or not
                {
                    t[i][j]= t[i-1][j-arr[i-1]]  || t[i-1][j];
                }
                else 
                {
                    t[i][j]=t[i-1][j];
                }
                    
            }
        }
        
        return t[n][sum];
    }