    void reverseRecursion(ListNode* &head, ListNode* curr, ListNode* prev)
    {
        if(curr==NULL)//it has reached to the last position
        {
            head=prev;//assign head to last and return it
            return;
        }

        ListNode* temp=curr->next;
        reverseRecursion(head,temp,curr);
        curr->next=prev;
    }
    
    ListNode* reverseList(ListNode* head) {

        //Iterative Approach
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        
//         while(curr!=NULL)//iterate till curr becomes null
//         {

//             ListNode* temp=curr->next;
//             curr->next=prev;//reversing the pointer
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
        
        //reverseRecursion(head, curr,prev);
        //return head;
	    
	    
	    //Method 3:
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* newhead=reverseList(head->next);//it will automatically has head 
        
        head->next->next=head;//ulta gumma do shuru ke block ko
        head->next=NULL;
        return newhead;
    }



    //codeStudio

    Node* reverse2(Node* &head)
{
    if(head==NULL || head->next==NULL)
        	return head;
   
    Node* newhead=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

/*
void reverse1(Node* &head, Node* curr,Node* prev)
{
    //Base condition
    if(curr==NULL)
    {
       head=prev;
        return;
    }
        
    
    Node* forward=curr->next;
    reverse1(head,forward,curr);
    curr->next=prev;
}
*/

Node* reverseLinkedList(Node *head)
{
    /* 1st iterative method	
    Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
	*/
 /*   
    //2nd recursive method
    	Node* prev=NULL;
        Node* curr=head;
    reverse1(head,curr,pruev);
    return head;
*/
    
    // 3rd recursive method
    return reverse2(head);
}  
