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

    return 0;
}