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
        
        if(head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* node1=head;
        ListNode* node1prev=node1;
        int k=1;
        
        while(k!=n)
        {
            node1=node1->next;
            k++;
        }
        
        if(node1->next==NULL)
        {
            return head->next;
        }
        
        ListNode* node2=head;
        ListNode* node2prev=node2;
        
        while(node1->next!=NULL)
        {
            node1=node1->next;
            node2prev=node2;
            node2=node2->next;
        }
        
        node2prev->next=node2->next;
        node2->next=NULL;
        
        return head;
    }
};