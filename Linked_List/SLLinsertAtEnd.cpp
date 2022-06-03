#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this -> data=data;
        this -> next=NULL;
    }
};



void insertAtEnd(Node* &tail,Node* &head,int data)
{
    if(tail==NULL)//first element to be inserted
    {
       Node* temp=new  Node(data);//create node and assign it to head and tail
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp=new  Node(data);
        tail -> next = temp;
        tail=temp;
    }
    

}

void printll(Node* temp)//printing of the node 
{
    //Node* temp=head;
    while(temp!=NULL)
    {
        cout<< temp-> data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    
}

int main(){

    Node* tail=NULL;
    
    
    Node* head= NULL;
    
    insertAtEnd(tail,head,6);
    printll(head);
    insertAtEnd(tail,head,3);
    printll(head);
    insertAtEnd(tail,head,4);
    printll(head);
    insertAtEnd(tail,head,5);
    printll(head);
    return 0;
}