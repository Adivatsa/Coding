    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
       
       //1st method using three linked list and mergering them all 
       
       Node* zerohead=new Node(-1); //create dummy node and assing tail which will insert value in LL
       Node* zerotail=zerohead;
       Node* onehead=new Node(-1); 
       Node* onetail=onehead;
       Node* twohead=new Node(-1);
       Node* twotail=twohead;
       
       
       Node* temp=head;
       while(temp!=NULL)
       {
           if(temp->data==0)
            {
                Node* newNode = new Node(0);
                zerotail->next=newNode;
                zerotail=newNode;
            }
            else if(temp->data==1)
            {
                Node* newNode = new Node(1);
                onetail->next=newNode;
                onetail=newNode;
            }
            else if(temp->data==2)
            {
                Node* newNode = new Node(2);
                twotail->next=newNode;
                twotail=newNode;
            }
            temp=temp->next;
       }
       
       if(onetail==onehead)
       {
           zerotail->next=twohead->next;
           twotail->next=NULL;
       }
       else
       {
           zerotail->next=onehead->next;
           onetail->next=twohead->next;
           twotail->next=NULL;
       }
       return zerohead->next;
     
       
       
       
       //2nd method
        /* Using the count variable and changing the linked list TC=O(n) SC=O(1)
        int zerocount=0;
        int onecount=0;
        int twocount=0;
        Node* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->data==0)
                zerocount++;
            else if (temp->data==1)
                onecount++;
            else if (temp->data==2)
                twocount++;
                
            temp=temp->next;
        }
        
        Node* curr=head;
        while(curr!=NULL)
        {
            if(zerocount>0)
                {
                    curr->data=0;
                    zerocount--;
                }
            else if(onecount>0)
                {
                    curr->data=1;
                    onecount--;
                }
            else if(twocount>0)
                {
                    curr->data=2;
                    twocount--;
                }
            curr=curr->next;
        }
        
        return head;
    */ 
    }