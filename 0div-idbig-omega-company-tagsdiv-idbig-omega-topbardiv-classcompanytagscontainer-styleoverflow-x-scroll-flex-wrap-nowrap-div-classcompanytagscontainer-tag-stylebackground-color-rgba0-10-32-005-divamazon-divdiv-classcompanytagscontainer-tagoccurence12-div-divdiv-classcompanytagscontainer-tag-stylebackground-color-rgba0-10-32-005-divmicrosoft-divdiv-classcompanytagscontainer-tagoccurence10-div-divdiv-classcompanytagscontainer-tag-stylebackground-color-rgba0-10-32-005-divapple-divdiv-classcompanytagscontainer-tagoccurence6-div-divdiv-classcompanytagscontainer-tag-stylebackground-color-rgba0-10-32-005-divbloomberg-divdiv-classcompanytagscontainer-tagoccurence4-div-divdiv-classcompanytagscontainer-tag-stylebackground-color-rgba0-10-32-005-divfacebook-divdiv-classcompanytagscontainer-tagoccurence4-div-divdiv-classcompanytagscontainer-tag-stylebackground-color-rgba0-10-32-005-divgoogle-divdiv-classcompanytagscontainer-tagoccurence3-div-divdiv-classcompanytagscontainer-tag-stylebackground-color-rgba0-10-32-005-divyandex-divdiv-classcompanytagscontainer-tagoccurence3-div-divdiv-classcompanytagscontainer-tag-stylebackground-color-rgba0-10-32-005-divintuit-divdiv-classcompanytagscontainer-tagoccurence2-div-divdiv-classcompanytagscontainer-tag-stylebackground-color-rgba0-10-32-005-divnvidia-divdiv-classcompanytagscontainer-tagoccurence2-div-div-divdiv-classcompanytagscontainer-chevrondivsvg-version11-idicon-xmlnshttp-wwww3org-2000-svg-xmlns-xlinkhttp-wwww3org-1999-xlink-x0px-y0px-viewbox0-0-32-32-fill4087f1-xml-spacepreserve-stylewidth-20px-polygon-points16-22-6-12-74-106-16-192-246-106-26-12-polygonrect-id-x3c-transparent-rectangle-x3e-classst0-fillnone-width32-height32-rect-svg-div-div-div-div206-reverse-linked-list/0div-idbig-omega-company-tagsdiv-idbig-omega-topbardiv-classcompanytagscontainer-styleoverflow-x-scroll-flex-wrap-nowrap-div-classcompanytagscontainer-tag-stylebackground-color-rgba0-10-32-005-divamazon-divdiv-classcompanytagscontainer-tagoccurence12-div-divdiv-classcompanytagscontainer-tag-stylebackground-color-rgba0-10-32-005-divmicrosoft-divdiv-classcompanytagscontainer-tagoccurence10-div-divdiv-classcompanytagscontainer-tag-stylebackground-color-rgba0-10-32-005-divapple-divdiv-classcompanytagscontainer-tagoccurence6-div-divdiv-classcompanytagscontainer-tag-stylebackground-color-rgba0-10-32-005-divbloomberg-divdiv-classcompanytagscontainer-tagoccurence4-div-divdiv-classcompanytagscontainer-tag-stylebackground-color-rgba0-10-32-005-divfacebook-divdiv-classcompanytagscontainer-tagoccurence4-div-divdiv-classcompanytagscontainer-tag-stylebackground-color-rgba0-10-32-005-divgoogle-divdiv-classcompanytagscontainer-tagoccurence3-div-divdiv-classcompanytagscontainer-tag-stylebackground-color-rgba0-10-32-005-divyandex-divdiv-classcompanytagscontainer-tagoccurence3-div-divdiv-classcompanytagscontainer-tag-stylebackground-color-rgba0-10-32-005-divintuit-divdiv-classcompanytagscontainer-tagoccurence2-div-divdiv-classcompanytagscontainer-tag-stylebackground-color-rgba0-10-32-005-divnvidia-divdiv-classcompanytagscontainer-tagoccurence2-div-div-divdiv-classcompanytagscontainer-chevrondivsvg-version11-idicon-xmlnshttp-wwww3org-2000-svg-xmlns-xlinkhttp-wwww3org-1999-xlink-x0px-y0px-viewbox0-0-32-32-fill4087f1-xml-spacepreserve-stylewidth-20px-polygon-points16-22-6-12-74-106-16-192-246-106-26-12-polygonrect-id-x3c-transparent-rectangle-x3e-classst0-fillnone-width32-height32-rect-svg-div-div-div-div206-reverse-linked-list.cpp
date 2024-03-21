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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* x=dummy;
        ListNode* y=x->next;

        while(y!=NULL && y->next)
        {
            ListNode* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }

        return dummy->next;

    }
};