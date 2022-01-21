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
        
//         int diff=right-1-left+2;
//         diff--;
        
//         ListNode* temp=head;
//         ListNode* belt=head;
        
//         int c=1;
        
//         while(c!=left && temp!=NULL)
//         {
//             temp=temp->next;
//             belt=belt->next;
//             c++;
//         }
       
        
//         while(diff && temp!=NULL)
//         {
//             int c=diff;
//             if(diff==1)
//                 break;
//             while(c-- && belt!=NULL)
//             {
//                 belt=belt->next;
//             }
//             swap(temp->val,belt->val);
//             temp=temp->next;
//             belt=temp;
//             diff-=2;
//         }
        
//         if(diff==1)
//         swap(temp->val,temp->next->val);
        
//         return head;
        
        if(left==right)
            return head;
        
        ListNode* temp=new ListNode(0);
        temp->next=head;
        
        ListNode* prev=temp;
        
        for(int i=0;i<left-1;i++)
        {
            prev=prev->next;
        }
        //prev=prev->next;
   
        
        ListNode* start=prev->next;
        ListNode* ahead=start->next;
        
        int flag=0;
        for(int i=0;i<right-left;i++)
        {
            // if(ahead->next==NULL)
            // {
            //      flag=1;
            //     break;
            // }
            start->next=ahead->next;
            ahead->next=prev->next;
            prev->next=ahead;
            ahead=start->next;
        }
        
        // if(flag==1)
        // {
        //     swap(prev->val,ahead->val);
        // }
        
        return temp->next;
        
        
    }
};