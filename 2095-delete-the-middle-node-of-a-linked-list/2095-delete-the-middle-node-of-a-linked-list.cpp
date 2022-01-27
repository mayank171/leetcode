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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        if(head->next==NULL)
            return NULL;
        
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;
            
        int flag=0;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
            if(flag==0)
                flag=1;
            else
                prev=prev->next;
            if(fast->next!=NULL)
                fast=fast->next;
            else
                break;
            
        }
        // cout<<prev->val;
        // cout<<slow->val;
        prev->next=slow->next;
        
        return head;
        
        
    }
};