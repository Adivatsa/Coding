    int mod=1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        
        //put the boundary values also
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        //sort them in increasiung order
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        //take out max value difference from both the vector
        int maxih=horizontalCuts[0];
        int maxiv=verticalCuts[0];

            for(int i=1; i<horizontalCuts.size(); i++)
            {
                maxih=max(maxih,(horizontalCuts[i]-horizontalCuts[i-1]));
            }
            for(int i=1; i<verticalCuts.size(); i++)
            {
                maxiv=max(maxiv,(verticalCuts[i]-verticalCuts[i-1]));
            }
        //Return the max of v1* max of v2
        return (long)maxiv*maxih%mod;
    }