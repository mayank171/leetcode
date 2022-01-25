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
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode* temp=head;
        
        int n=0;
        
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        
        stack<pair<int,int>> stk;
        
        vector<int> ans(n,0);
        
        temp=head;
        int i=0;
        stk.push({temp->val,i});
        temp=temp->next;
        i++;
        
        while(temp!=NULL)
        {
            while(!stk.empty())
            {
                if(stk.top().first<temp->val)
                {
                     int top_val=stk.top().first;
                     int ind=stk.top().second;
                     stk.pop();
                     ans[ind]=temp->val;
                }
                else
                {
                    break;
                }
            }
            stk.push({temp->val,i});
            i++;
            temp=temp->next;
        }
        
        return ans;
        
    }
};