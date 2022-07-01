    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        //In this from small to big building we require to use brick or ladder
        //to optimal the case we can use ladder at highest number of differenece 
        //rather than bricks
        //we have to return the max reach building index
        
        //Whenever brick count is going into negative we can use ladder
        //and brick count will be added by max differece till reached here any encountered
        //so to store max difference use a max heap
        
        int i;
        priority_queue<int> q;
        for(i=0; i<heights.size()-1; i++)
        {
            int d=heights[i+1]-heights[i];
            
            //if difference is negative means we have to jump 
            //otherwise we have to use ladder or brick
            if(d>0)
            {
                bricks=bricks-d;
                q.push(d);
                //if brick count is negative then use ladder till ladder is not 0
                if(bricks<0)
                {
                    if(ladders<=0)
                        return i;
                    ladders--;
                    bricks=bricks+q.top();
                    q.pop();
                }
            }
        }
        //we have reached the last position
        return i;
        
    }