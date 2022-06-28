//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        //Find val/wt for item a and item b
        //sort in decresing order so if item 1 is graeter then return true else false
        double vperw1=(double)a.value/(double)a.weight;
        double vperw2=(double)b.value/(double)b.weight;
        if(vperw1>vperw2)
            return true;
        else
            return false;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //First sort according to val/weight of item array
        //Store two variable one will store total value and other with current alloted weight till now
        //Iterate over item array and find if currweight and item weight less than W
        //then add the value in total value and increase the current weight
        //otherwise find the remaining weight and multiply it by item val/weight
        //At last return the total value

        //Everwhere type cast to double from int
        sort(arr,arr+n,comp);
        
        double val=0.0;
        int currwt=0;
        
        for(int i=0; i<n; i++)
        {
            if(currwt+arr[i].weight<=W)
            {
                currwt+=arr[i].weight;
                val+=arr[i].value;
                
            }
            else
            {
                int rem=W-currwt;
                val=val+(((double)arr[i].value/(double)arr[i].weight)*(double)rem);
                break;
            }
        }
        return val;
    }
};