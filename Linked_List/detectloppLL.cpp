    bool detectLoop(Node* head)
    {
        /*//Method 1: Using map we will store node and mark it as true 
        //if again visited then it will make it as false so return loop is there
        unordered_map<int, bool> m;
        
        if(head==NULL|| head->next==NULL)
            return false;
            
        Node* temp=head;
        while(temp->next!=NULL)
        {
            m[temp->data]=true;
            if(m[temp->data]==false)
            {
                return true;
                break;
            }
            temp=temp->next;
        }
        return false;*/
        
        //Method 2: Using slow and fast Pointer 
        //slow will go one step and fast will go for two step
        //whenever slow==fast it means cycle is there and if slow=NULL means no cycle
        
        Node* slow=head;
        Node* fast=head;
        if(head==NULL || head->next==NULL)
            return false;
            
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }