class dsu
{
    public:
    vector<int> parent;
    vector<int> size;
    int sz;
    
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
        if(u==parent[u])
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
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[2]<b[2])
            return true;
        return false;
    }
    
    static bool comp1(vector<int> &a,vector<int> &b)
    {
        if(a[2]<b[2])
            return true;
        return false;
    }
    
    
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        dsu d(n);
        
        int esize=edgeList.size();
        vector<pair<int,int>> adj[n];
        
        int qsize=queries.size();
        vector<vector<int>> q;
        
        for(int i=0;i<qsize;i++)
        {
            q.push_back({queries[i][0],queries[i][1],queries[i][2],i});
        }
        
        sort(edgeList.begin(),edgeList.end(),comp);
        sort(q.begin(),q.end(),comp);
        
        
        vector<bool> ans(qsize,false);
        int j=0;
        
        for(int i=0;i<qsize;i++)
        {
            int pu=q[i][0];
            int pv=q[i][1];
            int dist=q[i][2];
            
            
            int flag=0;
            for(;j<esize;j++)
            {
                int ed=edgeList[j][2];
                if(ed<dist)
                {
                    d.findUnion(edgeList[j][0],edgeList[j][1]);
                }
                else
                {
                    break;
                }
                    
            }
            
            if(d.findParent(pu)==d.findParent(pv))
                ans[q[i][3]]=true;
            else
                ans[q[i][3]]=false;
                
        }
        
        return ans;
    }
};




















