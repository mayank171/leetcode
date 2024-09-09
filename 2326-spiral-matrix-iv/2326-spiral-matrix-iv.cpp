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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
        int ni=v.size();
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int ind=0;
        int x=0;
        int y=0;
        ans[x][y]=v[ind];
        ind++;
        int ind1=0;
        
        vector<int> vis(n*m,0);
        vis[0]=1;
        
           
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     cout<<ans[i][j]<<" ";
//                 }
//                 cout<<endl;
//             }
//             cout<<"----"<<endl;
        
        for(int i=0;i<m*n;i++)
        {
            vis[x*n+y]=1;
            int p=x;
            int q=y;
            x=x+dx[ind1];
            y=y+dy[ind1];
             if(ind>=ni)
                break;
            
            if(x<m && x>=0 && y<n && y>=0 && vis[x*n+y]==0)
            {
                ans[x][y]=v[ind];
                ind++;
               // vis[x*m+y]=1;
            }
            else
            {
               
                ind1=(ind1+1)%4;
                x=p+dx[ind1];
                y=q+dy[ind1];
                ans[x][y]=v[ind];
                ind++;
              // vis[x*m+y]=1;
            }
            
            if(ind>=ni)
                break;
            
            // for(int i=0;i<m;i++)
            // {
            //     for(int j=0;j<n;j++)
            //     {
            //         cout<<ans[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<"----"<<endl;
        }
        return ans;
        
    }
};