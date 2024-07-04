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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* temp=head;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* node=dummy;
        
        while(temp)
        {
            if(temp->val==0)
            {
                ListNode* temp1=temp->next;
                int sum=0;
                while(temp1)
                {
                    sum+=temp1->val;
                    temp1=temp1->next;
                    if(temp1->val==0)
                        break;
                }
                ListNode* node1=new ListNode(sum);
                node->next=node1;
                node=node->next;
                temp=temp1;
                
                if(temp->next==NULL)
                {
                    node=NULL;
                    break;
                }
            }
            else
            {
                temp=temp->next;
            }
        }
        
        return dummy->next;
    }
};