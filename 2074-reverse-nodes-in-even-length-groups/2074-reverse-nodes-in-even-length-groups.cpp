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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        vector<vector<int>> v;
        
        int i=0;
        
        ListNode* temp=head;
        
        
        
        int ind=1;
        int j=0;
        
        int flag=1;
        
        while(temp!=NULL)
        {
            vector<int> tp;
            if(flag==1)
            {
                ListNode* temp1=temp;
                int j=0;
                while(j<ind && temp1!=NULL)
                {
                    tp.push_back(temp1->val);
                    j++;
                    temp1=temp1->next;
                }
                v.push_back(tp);
                // for(auto &it:tp)
                // {
                //     cout<<it<<" ";
                // }
                // cout<<endl;
                
                temp=temp1;
                flag*=-1;
                ind++;
                continue;
            }
            else
            {
                ListNode* temp1=temp;
                int j=0;
                while(j<ind && temp1!=NULL)
                {
                    tp.push_back(temp1->val);
                    j++;
                    temp1=temp1->next;
                }
                v.push_back(tp);
                // for(auto &it:tp)
                // {
                //     cout<<it<<" ";
                // }
                // cout<<endl;
                
                temp=temp1;
                flag*=-1;
                ind++;
                continue;
            }
            
            if(temp->next==NULL)
                v.push_back(tp);
           
        }
        
        
        
        temp=head;
        
        flag=1;
        
        ind=1;
        
        while(temp)
        {
            if(v[ind-1].size()%2!=0)
            {
                ListNode* temp1=temp;
                int j=0;
                while(j<ind && temp1!=NULL)
                {
                    temp1->val=v[ind-1][j];
                    j++;
                    temp1=temp1->next;
                }
                flag*=-1;
                ind++;
                temp=temp1;
            }
            else
            {
                ListNode* temp1=temp;
                int j=v[ind-1].size()-1;
                while(j>=0 && temp1!=NULL)
                {
                    temp1->val=v[ind-1][j];
                    j--;
                    temp1=temp1->next;
                }
                flag*=-1;
                ind++;
                temp=temp1;
            }
        }
        
        
        return head;
        
    }
};