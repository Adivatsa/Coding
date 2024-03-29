class Queue {
    int size;
    int * arr;
    int frnt;
    int rear;
public:
    Queue() {
        size=100000;
        arr=new int[size];
        frnt=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frnt==rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size)
            cout<<"Queue i s Full"<<endl;
        else
        {
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(frnt==rear)
            return -1;
        else
        {
            int val=arr[frnt];
            arr[frnt]=0;
            frnt++;
            if(frnt==rear)
            {
                frnt=0;
                rear=0;
            }
            return val;
        }
    }

    int front() {
        // Implement the front() function
        if(frnt==rear)
            return -1;
        else
            return arr[frnt];
    }
};