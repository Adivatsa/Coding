class MedianFinder {
public:
    //here we have to insert element one by one and find median for them
    //use max heap and min heap
    //if both are empty then insert into max heap
    //if num is less than max heap top then insert into max heap otherwise min heap
    //check if size difference greater than 1 then transfer max heap to min heap largest otherwise vice versa which has size greater
    //find median if both size same then avg of both top otherwise size greater top
    
    //Max Heap
    priority_queue<int> mx;
    //min heap
    priority_queue<int, vector<int> , greater<int>>mn;
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        
        //if both are empty and num is less than max heap top then insert into max heap
        if(mx.size()==0 || num<mx.top())
            mx.push(num);
        else
            mn.push(num);
        
        //Check size diffeence greater thn 1
        if(mx.size()> mn.size()+1)//max heap size is greater
        {
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size()>mx.size()+1)//min heap size is greater 
        {
            mx.push(mn.top());
            mn.pop();
        }   
    }
    
    double findMedian() {
        
        //if size of both are equal
        double ans;
        if(mx.size()==mn.size())
        {
            ans=(mx.top()+mn.top())/2.0;
        }
        else if(mx.size()>mn.size())
        {
            ans=mx.top();
        }
        else
            ans=mn.top();
        
        return ans;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */