struct Node* reverseDLL(struct Node * head)
{
    if(head==NULL || head->next==NULL)
        return head;
        
    struct Node* newhead=reverseDLL(head->next);
    //only reverse the first node 
    newhead->prev=NULL;
    head->next->next=head;
    head->prev=head->next->next;
    head->next=NULL;
    
    return newhead;
}