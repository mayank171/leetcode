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
    int pairSum(ListNode* head) {
        
         ListNode* temp=head;
        
        int ct=0;
        
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }
        
        int ctr=ct/2;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* nxt=new ListNode();
        
        while(ctr--)
        {
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        
        head->next=nxt;
        head=prev;
        
        temp=head;
        
        
        
        ctr=ct/2;
        ListNode* temp1=head;
        ListNode* temp2=head;
        
        while(ctr--)
        {
            temp2=temp2->next;
        }
        
        int maxi=-1;
        while(temp2!=NULL)
        {
            maxi=max(maxi,temp1->val+temp2->val);
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        
        
        return maxi;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         ListNode* temp=head;
        
//         int ct=0;
        
//         while(temp!=NULL)
//         {
//             ct++;
//             temp=temp->next;
//         }
        
//         vector<int> sum(ct/2);
        
//         int p=0;
//         int q=0;
        
//         temp=head;
        
//         while(temp!=NULL)
//         {
//             if(p<ct/2)
//             {
//                 sum[p]=(temp->val);
//                 p++;
//                 q++;
//             }
//             else
//             {
//                 q--;
//                 sum[q]+=temp->val;
//             }
//             temp=temp->next;
//         }
        
        
//         return *max_element(sum.begin(),sum.end());
        
    }
};