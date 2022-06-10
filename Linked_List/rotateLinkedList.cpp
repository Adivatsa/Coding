/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        //We have to rotate the linked list
        //Just count the number of nodes and itertate to last node
        //connect first and last node
        //reach till node we has to be last using s-k>1
        //point this node to null
        //and return its next as ans
        //if k has value greater than number of nodes used modulus
        
        if(head==NULL)
            return head;
        ListNode* curr=head;
        int s=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            s++;
        }
        k=k%s;
        curr->next=head;
        curr=head;
        
        while(s-k>1)
        {
            curr=curr->next;
            s--;
        }
        ListNode* prev=curr;
        curr=curr->next;
        prev->next=NULL;
        head=curr;
        return head;
        
    }
};