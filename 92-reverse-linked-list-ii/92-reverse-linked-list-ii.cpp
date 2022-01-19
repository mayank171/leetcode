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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int diff=right-1-left+2;
        diff--;
        
        ListNode* temp=head;
        ListNode* belt=head;
        
        int c=1;
        
        while(c!=left && temp!=NULL)
        {
            temp=temp->next;
            belt=belt->next;
            c++;
        }
        //cout<<"nvdkvndkv";
        
        while(diff && temp!=NULL)
        {
            int c=diff;
            if(diff==1)
                break;
            while(c-- && belt!=NULL)
            {
                belt=belt->next;
            }
            swap(temp->val,belt->val);
           // cout<<temp->val<<" "<<belt->val<<endl;
            temp=temp->next;
            belt=temp;
            diff-=2;
        }
        
        if(diff==1)
        swap(temp->val,temp->next->val);
        
        return head;
        
        
    }
};