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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* temp=head;
        
        
        vector<int> ans;
        
        pair<int,int> max;
        max={-1,-1};
        pair<int,int> min;
        min={-1,-1};
        int c=1;
        
        int ct_cri=0;
        
        unordered_set<int> st;
        int x=0,y=0;
        
        while(temp->next->next!=NULL)
        {
            if(temp->next->val < temp->val && temp->next->val<temp->next->next->val
              || temp->next->val > temp->val && temp->next->val > temp->next->next->val)
            {
                ct_cri++;
                if(min.first==-1)
                {
                    min.first=c+1;
                }
                else if(min.second==-1)
                {
                    min.second=c+1;
                    x=min.second;
                }
                else
                {
                    
                    x=c+1;
                    if(abs(min.first-min.second)>abs(x-(c+1)) && y==0)
                    {
                        min.first=min.second;
                        min.second=c+1;
                    }
                    else  if(abs(min.first-min.second)>abs(x-(y)) && y!=0)
                    {
                        min.first=x;
                        min.second=y;
                    }
                   
                }
                
                if(max.first==-1)
                {
                    max.first=c+1;
                    y=c+1;
                }
                else if(max.second==-1)
                {
                    max.second=c+1;
                    y=c+1;
                }
                else
                {
                    max.second=c+1;
                    y=c+1;
                }
            }
 
            temp=temp->next;
            c++;
        }
        
        cout<<min.first<<" "<<min.second<<endl;
        cout<<max.first<<" "<<max.second<<endl;
        
        if(ct_cri<2)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(abs(min.first-min.second));
            ans.push_back(abs(max.first-max.second));
        }
        
        return ans;
    }
};