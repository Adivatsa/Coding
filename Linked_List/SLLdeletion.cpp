#include<iostream>
using namespace std;

class Node
{   
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data= data;
        this -> next= NULL;

    }

    ~Node()
    {
        int value=this->data;
        while(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<" Memory is deleted of Node with value "<<value<<endl;
    }
};

void insertAtMid( Node* & head, Node* &tail, int position, int data)
{
    if(position==1) 
    {
        Node* temp=new Node(data);
        temp -> next= head;
        head= temp;
        return;
    }
    Node* temp=head;
    int st=1;
    while(st<position-1)
    {
        temp= temp->next;
        st++;
    }
    
    Node* mid=new Node(data);
    if(temp->next !=NULL)
    {
        mid->next=temp->next;
        temp->next=mid;
    }
    else
    {
        temp->next=mid;
        tail=mid;
    }
    


}
void print(Node* temp)
{
    while(temp!=NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}
/*
if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp-> next= NULL;
        delete temp;
    }
    else
    {
    Node* curr=head;
    Node* prev=NULL;
    
    int s=1;
    while(s<position)
    {
        prev=curr;
        curr=curr->next;
        s++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }
    */

void deleteNode(Node* &head, int position)
{
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp-> next= NULL;
        delete temp;
    }
    else
    {
    Node* curr=head;
    Node* prev=NULL;
    
    int s=1;
    while(s<position)
    {
        prev=curr;
        curr=curr->next;
        s++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }    
}

int main(){

    
    Node* node1=new Node(2);
    Node* head=node1;
    Node* tail=node1;
    

    int position;
    print(head);
    insertAtMid(head,tail,1,5);
    print(head);
    insertAtMid(head,tail,1,6);
    print(head);
    insertAtMid(head,tail,3,8);
    print(head);
    insertAtMid(head,tail,5,9);
    print(head);

    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;

    deleteNode(head, 3);
    print(head);

    return 0;
}