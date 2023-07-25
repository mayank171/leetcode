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
    
    void unionFind(int u,int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        
        if(pu==pv)
            return ;
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
        
        int size=edges.size();
        
        vector<int> blk1;
        vector<int> blk2;
        
        vector<int> parent(size+1,-1);
        
        for(int i=0;i<size;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(parent[v]==-1)
            {
                parent[v]=i;
            }
            else
            {
                blk1.push_back(u);
                blk1.push_back(v);
                blk2.push_back(edges[parent[v]][0]);
                blk2.push_back(edges[parent[v]][1]);
            }
        }
        
        for(auto &it:blk1)
            cout<<it<<" ";
        cout<<endl;
        
        for(auto &it:blk2)
            cout<<it<<" ";
        cout<<endl;
        
        
        
        if(blk1.size()==0 && blk2.size()==0)
        {
            dsu d(size+1);
            
            for(int i=0;i<size;i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                if(d.findParent(u)!=d.findParent(v))
                {
                    d.unionFind(u,v);
                }
                else
                {
                    return {u,v};
                }
            }
        }
        
        dsu d(size+1);            
        for(int i=0;i<size;i++)
        {
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(u==blk1[0] && v==blk1[1])
            {
                continue;
            }
            
            if(d.findParent(u)!=d.findParent(v))
            {
                d.unionFind(u,v);
            }
            else
            {
                return blk2;
            }
        }
        
        return blk1;
    }
};


























