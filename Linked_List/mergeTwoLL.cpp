 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //create the dummy node with -1 as value 
        //start adding value to next of dummy node 
        //at last return the next of dummy node
        
        //Base case 
        //Check any list is empty then return the other list
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        //create dummy node
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        ListNode* l1=list1;
        ListNode* l2=list2;
        
        while(l1!=NULL &&l2!=NULL)
        {
            
            if(l1->val > l2->val)
            {
                prev->next=l2;
                l2=l2->next;
                prev=prev->next;
            }
            else
            {
                prev->next=l1;
                l1=l1->next;
                prev=prev->next;
            }
        }
        
        while(l1!=NULL)
        {
            prev->next=l1;
            l1=l1->next;
            prev=prev->next;
        }
        
        while(l2!=NULL)
        {
            prev->next=l2;
            l2=l2->next;
            prev=prev->next;
        }
        //At last return head as next node of dummy
        return dummy->next;
        
    }