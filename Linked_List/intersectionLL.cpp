    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
//         //TC=O(m+n)  SC=O(m)
//         unordered_map<ListNode*, int>m;
        
//         ListNode* curr1=headA;
//         ListNode* curr2=headB;
//         while(curr1!=NULL)
//         {
//             m[curr1]++;
//             curr1=curr1->next;
        
//         }
//         while(curr2!=NULL)
//         {
//             if(m.find(curr2)!=m.end())
//                 return curr2;
//             curr2=curr2->next;
//         }
        
//         return curr2;
        
        //TC=O(m+n)  SC=O(1)
        
        // Using two pointer approach 
        //if any of the pointer reaches to the NULL just send pointer to different linked list  
        
        //Proff is a+c for LL1 b+c for LL2 then start travelling both pointer a+b+c then they will meet at when total a+b+c will be covered
        ListNode* curr1=headA;
        ListNode* curr2=headB;  
        
        while(curr1!=curr2)
        {
            if(curr1==NULL)//if null then send to other LL head position
                curr1=headB;
            else
                curr1=curr1->next;
            
            if(curr2==NULL)
                curr2=headA;
            else
                curr2=curr2->next;
        }
        return curr1;
    }