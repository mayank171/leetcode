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
    
    void findUnion(int u,int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        
        if(pu==pv)
            return ;
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
    
    int findComponents()
    {
        set<int> st;
        for(int i=0;i<sz;i++)
        {
            st.insert(parent[i]);
        }
        
        return st.size();
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        
        int n=strs.size();
        int l=strs[0].length();
        
        dsu d(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string x=strs[i];
                string y=strs[j];
                int ct=0;
                for(int k=0;k<l;k++)
                {
                    if(x[k]!=y[k])
                    {
                        ct++;
                    }
                    
                    if(ct>2)
                        break;
                }
                
                if(ct==2 || ct==0)
                {
                    //cout<<x<<" "<<y<<endl;
                    d.findUnion(i,j);    
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            d.findParent(i);
        }
        
        int ans=d.findComponents();
        
        return ans;
        
    }
};