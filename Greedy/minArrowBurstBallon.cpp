class Solution {
public:
    
    //In leetcode we have to write the comparator function as a static type
    //it will sort according to second value
    //phla vector ka elements second vector se chota hai toh true bhej do
    static bool comp(vector<int>&v1, vector<int>&v2)
    {
        if(v1[1]<v2[1])
            return true;
        else
            return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        //Main idea is that we have burst the ballons with min no of arrows
        //min one arrow will be there to burst the ballon
        //ballon has given ki x=1 to x=3 means 2 size ka ballon hai
        //agr humara first ballon ka end point se phle aur ush time tk jitne ballon ka 
        //start point hai toh wo sab ushi arrow se burst ho jaayenge
        //otherwise we require one more arrow and update the end point
        //Return the arrow count
        
        //Step 1: Sort according to end as increasing order
        sort(points.begin(), points.end(), comp);
        
        int arrow=1;
        int endpoint=points[0][1];
        
        for(int i=0; i<points.size(); i++)
        {
            if(endpoint<points[i][0])
            {
                arrow++;
                endpoint=points[i][1];
            }
        }
        return arrow;
    }