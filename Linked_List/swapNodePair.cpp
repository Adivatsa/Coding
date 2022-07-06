    ListNode* solve(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* curr=head;
        curr=curr->next;
        head->next=solve(head->next->next);
        curr->next=head;
        head=curr;
        return head;
        
    }
    ListNode* swapPairs(ListNode* head) {
        
        //My approach is i ll reverse only two nodes and others will automatically reversed by ewcursion
        //only reverse starting two nodes and connect to recursion call the head ka next
        //update the head and return
        return solve(head);
        
    }