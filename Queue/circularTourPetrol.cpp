  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    //This problem is similar to petrol pum problem of queue
    //pertol is amount of petrol which take u to that much kilomter
    //Distance is that much kilometer u have to reach
    //start from first index and find petrol-distance if >0 then go to 2nd index
    //otherwise consider it has def as while coiming back we require extra def petrol to reach next index
    int tour(petrolPump p[],int n)
    {
       int balance=0;
       int start=0;
       int kami=0;
       
       for(int i=0; i<n ;i++)
       {
           balance+=p[i].petrol-p[i].distance;
           if(balance<0)
                {
                    start=i+1;
                    kami+=balance;
                    balance=0;
                }
                
                
       }
       if(kami+ balance>=0)
            return start;
        else
            return -1;
       
    }