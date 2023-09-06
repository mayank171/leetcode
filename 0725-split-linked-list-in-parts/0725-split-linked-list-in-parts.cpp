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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int ct=0;
        ListNode* temp=head;
        int kk=k;
        
        while(temp)
        {
            temp=temp->next;
            ct++;
        }
        
        vector<ListNode*> ans;
        temp=head;
        
        while(k && temp)
        {
            if(ct%k==0)
            {
                ListNode* dummy=new ListNode(-1);
                ListNode* temp1=temp;
                dummy->next=temp1;
                int t=ct/k;
                t--;
                ct--;
                while(temp1 && t--)
                {
                    temp1=temp1->next;
                    ct--;
                }
                
                ans.push_back(dummy->next);
              
                if(temp1)
                {
                    temp=temp1->next;
                    temp1->next=NULL;         
                }
                else
                {
                    temp=NULL;
                }
            }
            else
            {
                ListNode* dummy=new ListNode(-1);
                ListNode* temp1=temp;
                dummy->next=temp1;
                int t=ct/k+1;
                t--;
                ct--;
                while(temp1 && t--)
                {
                    temp1=temp1->next;
                    ct--;
                }
                
                ans.push_back(dummy->next);
                
                if(temp1)
                {
                    temp=temp1->next;
                    temp1->next=NULL;         
                }
                else
                {
                    temp=NULL;
                }
            }
            k--;
        }
        
        while(ans.size()<kk)
        {
            ListNode* dummy=new ListNode(-1);
            ans.push_back(dummy->next);
        }
        
        return ans;
    }
};











