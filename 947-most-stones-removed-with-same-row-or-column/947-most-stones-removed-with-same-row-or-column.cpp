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
        }
        
        for(int i=0;i<sz;i++)
        {
            size.push_back(1);
        }
        
    }
    
    int findParent(int u)
    {
        if(u==parent[u])
            return parent[u];
        
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
    
    int findComponents()
    {
        set<int> st;
        for(int i=0;i<sz;i++)
        {
            if(parent[i]!=i)
                st.insert(parent[i]);
        }
        
        return st.size();
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int m=stones.size();
        
//         int maxi=0;
        
//         for(int i=0;i<m;i++)
//         {
//             maxi=max(maxi,max(stones[i][0],stones[i][1]));
//         }
        
        cout<<"dnsksvn"<<endl;
        
        vector<int> adj[20005];
        
        dsu d(20005);
        
        for(int i=0;i<m;i++)
        {
            adj[stones[i][0]].push_back(stones[i][1]+10001);
            adj[stones[i][1]+10001].push_back(stones[i][0]);
        }
        
        
        for(int i=0;i<20005;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(d.findParent(i)!=d.findParent(adj[i][j]))
                {
                    d.findUnion(i,adj[i][j]);
                }
            }
        }
        
        
        int ans=0;
        
        for(int i=0;i<20005;i++)
        {
            int x=d.findParent(i);
        }
        
        ans=d.findComponents();
        
        cout<<ans<<endl;
        
        set<int> st;
        for(int i=0;i<20005;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                st.insert(adj[i][j]);
            }
        }
        
        return m-ans;
        
    }
};





























