#include<bits/stdc++.h>

int maxpoint(int day, int last ,vector<vector<int>> &points, vector<vector<int>> &t)
{
    //Base case
    if(day==0)
    {
        int maxi=INT_MIN;
        //just ignore the last activity selected and find the max points it can give
        for(int i=0; i<points[0].size(); i++)
        {
            if(i!=last)
            {
               maxi=max(maxi, points[0][i]); 
            }
        }
        return maxi;
    }
    //Memoized 
    if(t[day][last]!=-1)
        return t[day][last];
    
    int maxi=INT_MIN;
    //iterate for all other activities and find optimal
    for(int i=0; i<points[0].size(); i++)
    {
        int ans=0;
        //iterate for each of the task and calculate the answer and acticity not equal to last activity
        if(i!=last)
        {
            //take current points and iterate for next day with current actiity
            ans= points[day][i]+ maxpoint(day-1, i, points,t);
            maxi=max(ans,maxi);
        }
    }
    t[day][last]=maxi;
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //Recursion
    int last=points[0].size();
    
    //With Memoization
    vector<vector<int>>t(n+1,vector<int>(last+1,-1));
    
    return maxpoint(n-1, last, points,t);
}