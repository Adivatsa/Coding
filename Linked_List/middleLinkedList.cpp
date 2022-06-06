    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        /*//Method 1:
        //Find the count of all element
        //find mid and return the mid element
        Node* curr=head;
        int cnt=0;
        while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }
        
        int mid= cnt/2+1;
        int s=1;
        
        
        Node* temp=head;
        while(s<mid)
        {
            temp=temp->next;
            s++;
        }
        return temp->data;*/
        
        //Method 2: Using slow and fast pointer
        //use slow 1 step and fast 2 step and return slow
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
        }
        return slow->data;
    }