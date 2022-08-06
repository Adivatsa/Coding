    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        //here we can find that for 60 mintotest and 15 min to die 
        //we have total 4 tests using a single pig
        //but we can also test 5 buckets as 4 has been checked then 5th will be poision
        //so equation will be = (4+1)^1= 5 buckets
        //here 4 is test and power with 1 is no of pig
        //so equation is (T+1)^(no of pig)= no of buckets
        //take log both sides and found number of pig
        //no of pig= log(buckets)/log(test+1)
        
        //fond total tests
        int t=minutesToTest/minutesToDie;
        
        return ceil(log(buckets)/log(t+1));  
    }