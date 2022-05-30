void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int m, int n, int scolor)
    {
        //if it is not in range and also scolor is not equal then return it
        if(sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc]!=scolor)
            return;
        
        //color it with new color
        image[sr][sc]=newColor;
        //left call
        dfs(image,sr,sc-1,newColor,m,n,scolor);
        //right call
        dfs(image,sr,sc+1,newColor,m,n,scolor);
        //up call
        dfs(image,sr-1,sc,newColor,m,n,scolor);
        //down call
        dfs(image,sr+1,sc,newColor,m,n,scolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        //In this question we have to color image with new image when it is same as source color
        //we can go to left right top and bottom 
        //just use dfs and if it matches with source color then color it with new color
        //TC=O(m*n) and SC=O(1)    m rows and n column
        
        //When source node is alredy coloured with new then no need to change 
        if(image[sr][sc]==newColor)
            return image;
        
        int m=image.size();//Row
        int n=image[0].size();//Column
        
        //FInd out the source color
        int scolor=image[sr][sc];
        
        //make dfs call 
        dfs(image,sr,sc,newColor,m,n,scolor);
        return image;
        
    }