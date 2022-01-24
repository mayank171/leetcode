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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* temp1=head;
        ListNode* temp2=head;
        
        int ct=0;
        while(temp1!=NULL)
        {
            ct++;
            temp1=temp1->next;
        }
        
        if(k==ct/2+1 && ct&1)
        {
            return head;
        }
        
        int first_node=k-1;
        int sec_node=ct-k;
        temp1=head;
        
        while(first_node--)
        {
            temp1=temp1->next;
        }
        
        while(sec_node--)
        {
            temp2=temp2->next;
        }
        
        swap(temp1->val,temp2->val);
        
        return head;
        
    }
};