#include<iostream>
using namespace std;

class Node
{   
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this -> data= data;
        this -> prev= NULL;
        this -> next= NULL;

    }

    //Destructor
    ~Node()
    {
        int value=this->data;
        while(this->next!=NULL)
        {
            this->next=NULL;
            this->prev=NULL;
            delete next;
            delete prev;
        }
        cout<<" Memory deleted with the value as "<<value<<endl;
    }
};

void insertdll( Node* & head, Node* &tail, int position, int data)
{
    if(head==NULL)
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        return;
    }
    if(position==1) 
    {
        Node* temp=new Node(data);
        temp -> next= head;
        head->prev=temp;
        head= temp;
        return;
    }
    
    
    Node* track=head;
    int s=1;
    while(s<position-1)
        {
            track=track->next;
            s++;
        }
    
    if(track==tail)
    {
        
        Node* temp=new Node(data);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;

    }
    else
    {
        
        Node* temp=new Node(data);
        temp->next=track->next;
        track->next->prev=temp;
        track->next=temp;
        temp->prev=track;
    }
    
    


}
void deletell(Node* &head, Node* &tail, int position)
{
    if(position ==1)
    {
        Node* temp= head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node* prev=NULL;
    Node* curr=head;
    int s=1;

    while(s<position)
    {
        prev=curr;
        curr=curr->next;
        s++;
    }
    if(curr->next==NULL)
    {
        curr->prev=NULL;
        prev->next=curr->next;
        tail=prev;
        curr->next=NULL;
        delete curr;

    }
    else
    {
        prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
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
int main(){

    
    
    Node* head=NULL;
    Node* tail=NULL;
    

    int position;
    
    insertdll(head,tail,1,5);
    print(head);
    insertdll(head,tail,1,6);
    print(head);
    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;
    insertdll(head,tail,3,8);
    print(head);
    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;
    print(head);
    insertdll(head,tail,2,9);
    print(head);

    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;

    deletell(head,tail,4);
    print(head);
    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;

    deletell(head,tail,1);
    print(head);
    cout<<" Head is at position "<<head->data<<endl;
    cout<<" Tail is at position "<<tail->data<<endl;

    

    return 0;
}