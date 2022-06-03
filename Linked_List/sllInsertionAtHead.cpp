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



void insertAtHead(Node* &head,int data)
{
    Node* temp=new  Node(data);
    temp -> next=head;
    head=temp;
}

void printll(Node* temp)
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

    Node* head=NULL;
    Node* node1=new Node(2);
    head=node1;
    
    printll(head);
    insertAtHead(head,6);
    printll(head);
    insertAtHead(head,3);
    printll(head);
    insertAtHead(head,4);
    printll(head);
    insertAtHead(head,5);
    printll(head);
    return 0;
}