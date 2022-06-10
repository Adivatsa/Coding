  Node* reverseLL(Node* &head)
  {
        Node* curr=head;
        Node* prev=NULL;
        Node* nextnode=NULL;
        
        while(curr!=NULL)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            
        }
        return prev;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        /*//store the contents of linked list in an array 
        //Just compare the array if it is palindrome or not
        //TC=O(n) and SC=O(n) due to vector
        
        Node* curr=head;
        vector<int> ans;
        while(curr!=NULL)
        {
            ans.push_back(curr->data);
            curr=curr->next;
        }
        
        int n =ans.size();
        
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(ans[i]==ans[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;*/
        
        
        //Method 2: TC=O(n) and SC=O(1)
        //we will find the middle of linked list
        //we will reverse the right half of the linked list
        //just compare start and aftr middle if equal then itertate otherwise not palindrome
        
        
        //Step1: find the middle of linked list
        //Use Slow and fast pointer 
        Node* slow=head;
        Node* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            //Slow chega one step and fast will go to two step
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
        }
        //slow is standing of the middle of linked list
        
        //Step 2: reverse the linked list and attach to the front of slow pointer
        slow->next=reverseLL(slow->next);
        
        //prev will have head of the reverse linked list
        Node* head2=slow->next;
        Node* head1=head;
        
        while(head2!=NULL)
        {
            if(head1->data==head2->data)
            {
                head1=head1->next;
                head2=head2->next;
            }
            else
                return false;
                
        }
        return true;
    }