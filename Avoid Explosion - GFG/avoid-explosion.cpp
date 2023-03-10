//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class dsu
{
    private:
    vector<int> parent;
    vector<int> size;
    int sz;
    
    public:
           dsu(int s)
           {
               sz=s;
               for(int i=0;i<sz;i++)
               {
                   parent.push_back(i);
                   size.push_back(1);
               }
           }
           
           int findParent(int u)
           {
               if(parent[u]==u)
                  return u;
               return parent[u]=findParent(parent[u]);
           }
           
           int getParent(int u)
           {
               return findParent(u);
           }
           
           void findUnion(int u,int v)
           {
               int pu=findParent(u);
               int pv=findParent(v);
               
               if(pu==pv)
               {
                   return ;
               }
               else if(size[pu]>=size[pv])
               {
                   parent[pv]=pu;
                   size[pu]+=size[pv];
               }
               else
               {
                   parent[pu]=pv;
                   size[pv]+=size[pu];
               }
           }
           
           void reverse(int u,int v)
           {
               if(size[u]>=size[v])
               {
                   size[u]-=size[v];
                   parent[v]=v;
               }
               else
               {
                   size[u]-=size[v];
                   parent[v]=v;
               }
           }
           
          void show()
          {
              for(int i=1;i<sz;i++)
              {
                  cout<<parent[i]<<" ";
              }
              cout<<endl;
          }
};


class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,vector<vector<int>> danger, int m)
    {
        dsu d(n+1);
        
        vector<string> ans;
        
        for(int i=0;i<n;i++)
        {
            int u=mix[i][0];
            int v=mix[i][1];
            
            // if(d.findParent(u)!=d.findParent(v))
            // {
                
                int pu=d.findParent(u);
                int pv=d.findParent(v);
                
                int flag=0;
                for(int j=0;j<m;j++)
                {
                    int du=danger[j][0];
                    int dv=danger[j][1];
                    
                    int pdu=d.findParent(du);
                    int pdv=d.findParent(dv);
                    
                    if((pdu==pu && pdv==pv)||(pdu==pv && pdv==pu))
                    {
                        flag=1;
                        break;
                    }
                }
                
                if(flag==1)
                {
                    ans.push_back("No");
                }
                else
                {
                    d.findUnion(u,v);
                    ans.push_back("Yes");
                }
               // d.show();
            // }
            // else
            // {
            //     ans.push_back("Yes");
            // }
        }
        
        return ans;
    }
};



























//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends