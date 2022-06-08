    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //Create a node dummy node and start adding the value
        //If carry is found add this to value
        //at last if carry is there append at last
        
        ListNode* dummy= new ListNode(-1);
        ListNode* l3=dummy;
        int carry=0;
        
        while(l1!=NULL && l2!=NULL)
        {
            int value= l1->val + l2->val + carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l2=l2->next;
            l1=l1->next;
        }
        while(l1!=NULL)
        {
            int value= l1->val  + carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int value= l2->val + carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l2=l2->next;
        }
        //Check if arry is there append at last
        if(carry!=0)
            l3->next=new ListNode(carry);
        
        
        return dummy->next;
        
    }