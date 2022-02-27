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
        
        if(k>ct/2)
        {
            k=ct-k+1;
        }
        
        temp1=head;
        int a=k;
        int b=ct-2*k+1;
        
        while(true)
        {
            a--;
            if(a==0)
                break;
            temp1=temp1->next;
            
        }
        
        temp2=temp1;
        
        while(b--)
        {
            temp2=temp2->next;
        }
       
        swap(temp1->val,temp2->val);
        
        return head;
        
        
    }
};