    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //Here we have to remove node from the last
        //Find total nodes in LL
        //Traverse till node less than that node
        //Remove the node
        
        if(head==NULL || head->next==NULL)
            return NULL;
        //Find total length of LL
        ListNode* curr=head;
        int s=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            s++;
        }
        //cout<<s;
        curr=head;
        //We have to remove this kth node from front
        int k=s-n;
        //Reach till k-1th node from front
        while(curr->next!=NULL && k>1 )
        {

            k--;
            curr=curr->next;
        }
        //if node to be remove is head just check once
        if(k==0)
        {
            curr=curr->next;
            head=curr;
        }
        else//otherwise remove the node
        {
            ListNode* t=curr->next;
            curr->next=curr->next->next;
            delete t;
        }
        
        
        //return the head of the linked list
        return head;
        
        
    }