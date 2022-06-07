/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    //we have to remove the duplicates from sorted linked list
    //check for one after another if same then u can point to next element
    
    /*if(head==NULL || head->next==NULL)
        return head;*/
        
    //check for till when list is not empty
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data==curr->next->data  && curr!=NULL)
        {
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else 
            curr=curr->next;
    }
    return head;
}