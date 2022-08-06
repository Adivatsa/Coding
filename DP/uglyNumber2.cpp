    int nthUglyNumber(int n) {
        
        //ugly number can be 1,2,3,4,5,6,8,9,10....
        //it should be multiple of 2,3,5
        //it will start from 1 and we will keep on multiplying then get the number
        
        vector<int> t(n,1);
        
        //three pointer approach which one will point to two multiple, three multiple, five multiple
        //whichever is minimum push into vector and increase the pointer of that
        int two=0;
        int three=0;
        int five=0;
        
        for(int i=1; i<n; i++)
        {
            //find the multiple and select minimum among them
            int twomultiple=t[two]*2;
            int threemultiple=t[three]*3;
            int fivemultiple=t[five]*5;
            //Taking minimum among them
            t[i]= min({twomultiple, threemultiple, fivemultiple});
            //increase the pointer for minimum selected
            if(t[i]==twomultiple)
                two++;
            if(t[i]==threemultiple)
                three++;
            if(t[i]==fivemultiple)
                five++;
        }
        return t[n-1];
        
    }