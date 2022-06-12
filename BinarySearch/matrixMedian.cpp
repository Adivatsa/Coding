int findocc(vector<int> mat,int target)
{
    //Finding the number less than or equal target
    int l=0;
    int h=mat.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(mat[mid]<=target)
            l=mid+1;
        else
            h=mid-1;        
    }
    //low pointee will have all number less than or equal target
    return l;  
}

int getMedian(vector<vector<int>> &matrix)
{
    //We have to find the median
    //Rowise and Column wise both are in sorted manner
    
    int n=matrix.size();//Row Size
    int m=matrix[0].size();//Column Size
    
    //Apply binary Search
    int low=0;
    int high=1e7;//Between 0 to infinity our median will lie
    
    while(low<=high)
    {
        int mid= low+(high-low)/2;
        
        int cnt=0;
        //Find the numbers which are less than mid
        for(int i=0; i<n; i++)
                cnt=cnt+ findocc(matrix[i],mid);
        //if cnt is less than size/2 then update the low
        if(cnt<=(n*m/2))
            low=mid+1;
        else
            high=mid-1;
    }
    //low will be ur median
    return low;
}