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
    ListNode* oddEvenList(ListNode* head) {
       
        int c=0;
        
        ListNode* temp=head;
        
        queue<int> even;
        queue<int> odd;
        int ind=1;
        
        while(temp!=NULL)
        {
            c++;
            if(ind&1)
            {
                odd.push(temp->val);
            }
            else
            {
                even.push(temp->val);
            }
            temp=temp->next;
            ind++;
        }
        
        if(c&1)
        {
            int mid=c/2;
            mid++;
            temp=head;
            
            while(mid--)
            {
                int x=odd.front();
                odd.pop();
                temp->val=x;
                temp=temp->next;
            }
            
            while(temp!=NULL)
            {
                int x=even.front();
                even.pop();
                temp->val=x;
                temp=temp->next;
            }
        }
        else
        {
            int mid=c/2;
           // mid++;
            temp=head;
            
            while(mid--)
            {
                int x=odd.front();
                odd.pop();
                temp->val=x;
                temp=temp->next;
            }
            
            while(temp!=NULL)
            {
                int x=even.front();
                even.pop();
                temp->val=x;
                temp=temp->next;
            }
        }
        return head;
       
    }
};