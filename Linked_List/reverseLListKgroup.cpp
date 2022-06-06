struct node *reverse (struct node *head, int k)
    { 
        // we have reverse linked list in k group
        //humme bs first k ko iterative way me reverse maarna hai
        //baaki sab already reverse kia hua hai
        if(head==NULL || head->next==NULL)
            return head;
        struct node* curr=head;
        struct node* prev=NULL;
        struct node* temp=NULL;
        
        //Reverse linked list of size k
        int i=0;
        while(i<k && curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            i++;
        }
        
        //attach the head to recursive obtained
        head->next=reverse(temp,k);
        //return the head 
        return prev;
        
    }


    //leetcode
        ListNode* reverseKGroup(ListNode* head, int k) {
        
        //check karega ki list k lenght ki hai ya nai agar nai hai toh head return maar dega taaki same list print ho jaaye
        ListNode* temp=head;
        for(int i=0; i<k;i++)
        {
            if(temp==NULL) return head;
            temp=temp->next;
        }
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* forward=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        int s=0;
        
        while(s<k && curr!=NULL )
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            s++;
        }
       
        head->next=reverseKGroup(forward,k);
        return prev;
        
    }