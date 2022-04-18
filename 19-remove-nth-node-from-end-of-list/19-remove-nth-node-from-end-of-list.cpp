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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* a=head;
        ListNode* b=head;
        
        int ct=n-1;
        
        while(ct-- && b!=NULL)
        {
            b=b->next;
        }
        
        
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        
        if(a->next!=NULL)
            nxt=a->next;
        
        while(b->next!=NULL)
        {
            prev=a;
            a=a->next;
            nxt=a->next;
            b=b->next;
            
        }
        
        if(prev==NULL)
        {
            if(nxt==NULL)
            {
                return NULL;
            }
            else
            {
                head=nxt;
                return head;
            }
        }
            
        else
            prev->next=nxt;
        
        return head;
        
    }
};