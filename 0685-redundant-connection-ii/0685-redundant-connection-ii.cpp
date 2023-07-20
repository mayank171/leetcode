class dsu
{
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
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else
        {
            size[pv]+=size[pu];
            parent[pu]=pv;    
        }
    }
};

class Solution {
public:
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis1(n+1,-1);
        vector<int> res;
        vector<int> blk1;
        vector<int> blk2;
        
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(vis1[v]==-1)
            {
                vis1[v]=i;
            }
            else
            {
                blk1.push_back(u);
                blk1.push_back(v);
                
                int ind=vis1[v];
                blk2.push_back(edges[ind][0]);
                blk2.push_back(edges[ind][1]);
                break;
            }
        }
        
        for(auto &it:blk1)
            cout<<it<<" ";
        cout<<endl;
        
        for(auto &it:blk2)
            cout<<it<<" ";
        cout<<endl;
        
        if(blk1.size()>0 && blk2.size()>0)
        {
            vector<int> ans;
            dsu d(n+1);
            for(int i=0;i<n;i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                
                if(u==blk1[0] && v==blk1[1])
                    continue;

                if(d.findParent(u)!=d.findParent(v))
                {
                    d.findUnion(u,v);
                }
                else
                {
                    ans.push_back(u);
                    ans.push_back(v);
                   // break;
                }
            }

            cout<<ans.size()<<endl;
            
            if(ans.size()==0)
            {
                return blk1;
            }
            
            return blk2;
        }
        
        
        vector<int> ans;
            dsu d(n+1);
            for(int i=0;i<n;i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                

                if(d.findParent(u)!=d.findParent(v))
                {
                    d.findUnion(u,v);
                }
                else
                {
                    ans.push_back(u);
                    ans.push_back(v);
                   // break;
                }
            }

        return ans;
    }
};