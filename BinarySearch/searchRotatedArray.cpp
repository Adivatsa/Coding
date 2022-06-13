// { Driver Code Starts
//Header Files
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int findpivotpos(int A[], int l, int h)
    {
        //pivot nekalne ke liye check kar lenge jaha pe bhi start element se bada end 
        //ho jaaye then that is pivot
        // 7 8 1 2 3 here at 1 2 is greater and 8 is also larger
        
        while(l<h)
        {
            int mid=l+(h-l)/2;
            
            //check if already sorted 
            if(A[l]<A[h])
                return l;
            else if(A[mid]>A[0])
                l=mid+1;
            else
                h=mid;
        }
        return l;
    }
    
    int bsearch(int A[], int l, int h,int key)
    {
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(A[mid]==key)
                return mid;
            if(A[mid]>key)
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
    //complete the function here
        
        //To search in sorted rotated array
        //first find out the pivot element position
        //pivot is smallest number in array
        //Apply binary search on based of two strings
        //0 to pivot-1 will be one sorted array and pivot to last will another sorted
        
        int pivotpos=findpivotpos(A,l,h);
        
        if(A[pivotpos]<=key && A[h]>=key)
            return bsearch(A,pivotpos,h,key);
        else
            return bsearch(A,0,pivotpos-1,key);
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;