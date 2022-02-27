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
        
        vector<int> sum(ct/2);
        
        int p=0;
        int q=0;
        
        temp=head;
        
        while(temp!=NULL)
        {
            if(p<ct/2)
            {
                sum[p]=(temp->val);
                p++;
                q++;
            }
            else
            {
                q--;
                sum[q]+=temp->val;
            }
            temp=temp->next;
        }
        
        
        return *max_element(sum.begin(),sum.end());
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         ListNode* temp=head;
//         int c=0;
        
//         while(temp!=NULL)
//         {
//             c++;
//             temp=temp->next;
//         }
        
//         c/=2;
        
//         vector<int> sum(c);
        
//         int p=0;
//         int q=0;
        
//         temp=head;
//         int flag=1;
//         int max_1=INT_MIN;
        
//         while(temp!=NULL)
//         {
//             if(p<c)
//             {
//                 sum[p]=temp->val;
//                 p++;
//                 //flag=-1;
//             }
//             else
//             {
//                 if(flag==1)
//                 {
//                     q=p;
//                     q--;
//                     flag*=-1;
//                 }
                
//                 sum[q]+=temp->val;
//                 if(sum[q]>max_1)
//                     max_1=sum[q];
//                 q--;
//             }
//             temp=temp->next;
            
            
//         }
        
//         return max_1;
        
    }
};