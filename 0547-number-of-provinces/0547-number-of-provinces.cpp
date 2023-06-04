class dsu
{
    vector<int> parent;
    vector<int> size;
    int sz;
    public:
    dsu(int z)
    {
        sz=z;
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
            return;
        else if(size[pu]>=size[pv])
        {
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else if(size[pv]>=size[pu])
        {
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        
    }
    
    int components()
    {
        set<int>st;
        for(int i=1;i<sz;i++)
        {
            st.insert(parent[i]);
        }
        
        return st.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& vp) {
        
        int n=vp.size();
        int m=vp[0].size();
        
        dsu d(n+1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vp[i][j]==1)
                {
                    if(d.findParent(i+1)!=d.findParent(j+1))
                    {
                        d.findUnion(i+1,j+1);
                    }
                }
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            d.findParent(i);
        }
        
        return d.components();
    }
};






















