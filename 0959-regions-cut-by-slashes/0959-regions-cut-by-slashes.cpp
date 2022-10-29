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
        
        if(size[pu]>=size[pv])
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
  
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dots=n+1;
        
        dsu d(dots*dots);
        
        for(int i=0;i<dots;i++)
        {
            for(int j=0;j<dots;j++)
            {
                if(i==0 || j==0 || i==dots-1 || j==dots-1)
                {
                    int cell=i*dots+j;
                    d.findUnion(0,cell);
                }
            }
        }
        
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='\\')
                {
                    int i1=i;
                    int j1=j;
                    int i2=i+1;
                    int j2=j+1;
                    
                    int ind1=i1*dots+j1;
                    int ind2=i2*dots+j2;
                    
                    if(d.findParent(ind1)!=d.findParent(ind2))
                    {
                        d.findUnion(ind1,ind2);
                    }
                    else
                    {
                        d.findUnion(ind1,ind2);
                        ans++;    
                    }
                }
                else if(grid[i][j]=='/')
                {
                    int i1=i;
                    int j1=j+1;
                    int i2=i+1;
                    int j2=j;
                    
                    int ind1=i1*dots+j1;
                    int ind2=i2*dots+j2;
                    
                    if(d.findParent(ind1)!=d.findParent(ind2))
                    {
                        d.findUnion(ind1,ind2);
                    }
                    else
                    {
                        d.findUnion(ind1,ind2);
                        ans++;    
                    }
                }
                    
            }
        }
        
        return ans;
    }
};
























