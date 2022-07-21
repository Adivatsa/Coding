    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL)
            return head;
        if(left==right)
            return head;

        ListNode* prev, *temp=NULL;
        //Create one dummy node so that if left is 1st index then we can reverse the whole LL
        ListNode* dummy=new ListNode(0);
        //connect dummy in front of head
        dummy->next=head;
        //asssign prev to dummy to skip from error for first node reversal
        prev=dummy;
        //find out the node previous to left pointyer
        for(int i=0; i<left-1; i++)
            prev=prev->next;
        //last will connect till right ka next wala node
        ListNode* last=prev->next;
        for(int j=0; j<right-left; j++)
        {
            //store prev ke aage wla
            temp=prev->next;
            //connect last ke aage wala as first as prev ka next to reverse
            prev->next=last->next;
            //shift last to last position
            last->next=last->next->next;
            //connect prev ka next to old previous
            prev->next->next=temp;
        }
        return dummy->next;
       
    }