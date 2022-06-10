ListNode* merge(ListNode* l, ListNode* r)
    {
        
        //merging the two sorted linked list
        //check if one ll is empty then return other
        if(l==NULL)
            return r;
        if(r==NULL)
            return l;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        while(l!=NULL && r!=NULL)
        {
            if(l->val > r->val)
            {
                prev->next=r;
                r=r->next;
                prev=prev->next;
            }
            else
            {
                prev->next=l;
                l=l->next;
                prev=prev->next;
            }
        }
        
        while(l!=NULL)
        {
            prev->next=l;
            l=l->next;
            prev=prev->next;
        }
        while(r!=NULL)
        {
            prev->next=r;
            r=r->next;
            prev=prev->next;
        
        }
        return dummy->next;
    
    }
    ListNode* mid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
            
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        
        //Merge Sort in Linked List
        //Algo
        //Divide the list into two parts using mid till they have 0 or 1 element
        //Merge two sorted list
        
        //Base case 
        //if 0 or 1 element then it that case it is been sorted
        if(head==NULL || head->next==NULL)
            return head;
        
        
        //Step1: Dividing LL into two parts
        ListNode* temp=mid(head);
        //first list head
        ListNode* l=head;
        //second list head
        ListNode* r=temp->next;
        //dividing link into two parts
        temp->next=NULL;//End of the first half
        
        
        //Recursive call to divide the Linked list
        l=sortList(l);
        r=sortList(r);
        
        
        //Merging the two sorted Linked list
        ListNode* ans=merge(l,r);
        
        return ans;
    }