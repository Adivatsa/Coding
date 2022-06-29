#include<iostream>
//#include<stack> // for stl use this library

using namespace std;

//creating a class for stack implement using array
class Stack{

    public:
    
    //To implement stack using array we have to take one array , its size and top of it

    int *arr;
    int size;
    int top;

    //constructor for stack class
    Stack(int size)
    {
        this->size=size;
        top=-1;
        arr=new int(size);

    }

    //there are four operations for thr stack
    //push, pop, size, top

    void push(int data)
    {
        if(size-top > 1)
        {
            top++;
            arr[top]=data;
        }
        else
            cout<<" Stack is full"<<endl;

    }

    void pop()
    {
        if(top>=0)
            top--;
        else
            cout<<" Stack is empty "<<endl;

    }

    int peak()
    {
        if(top>=0)
        {
            int ele=arr[top];
            return ele;
        }
            
        else
            return -1;
        
    }


};

int main()
{
    // using STL for stack push pop size and top operation
    // stack<int> s;
    // s.push(3);
    // s.push(9);
    // cout<<" Stack size is "<< s.size()<<endl;
    // cout<<" Stack top is "<< s.top()<<endl;
    // s.pop();
    // cout<<" Stack top is "<< s.top()<<endl;
    // s.pop();
    // cout<<" Stack top is "<< s.top()<<endl;


    //Stack using array implementation

    Stack st(5);
    st.push(5);
    st.push(9);
    st.push(98);
    st.push(5);
    st.push(9);
    
    cout<<" Stack top is "<< st.peak()<<endl;
    st.pop();
    cout<<" Stack top is "<< st.peak()<<endl;
    st.pop();
    cout<<" Stack top is "<< st.peak()<<endl;
    st.pop();
    cout<<" Stack top is "<< st.peak()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<" Stack top is "<< st.peak()<<endl;
    return 0;
}