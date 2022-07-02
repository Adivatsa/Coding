class MyCircularQueue {
    int size;
    int *arr;
    int f;
    int r;
public:
    MyCircularQueue(int k) {
        this->size=k;
        arr=new int[size];
        f=-1;
        r=-1;
        
    }
    
    bool enQueue(int value) {
        if((f==0 && r==(size-1)) || (r==f-1) )
            return false;
        
        if(f==-1)
        {
            f=0;
            r=0;
            arr[r]=value;
        }
        else if(f!=0 && r==(size-1))
        {
            r=0;
            arr[r]=value;
        }
        else
        {
            r++;
            arr[r]=value;
        }
        return true;
        
    }
    
    bool deQueue() {
        
        if(f==-1)
            return false;
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else if(f==(size-1))
            f=0;
        else
            f++;
        return true;
        
    }
    
    int Front() {
        if(f==-1)
            return -1;
        else
            return arr[f];
        
    }
    
    int Rear() {
        if(f==-1)
            return -1;
        else
            return arr[r];   
    }
    
    bool isEmpty() {
        if(f==-1)
            return true;
        else
            return false;
        
    }
    
    bool isFull() {
        if((f==0 && r==(size-1)) || (r==(f-1)%(size-1)))
            return true;
        else
            return false;
        
    }
};