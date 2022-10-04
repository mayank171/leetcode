class dsu1
{
    vector<int> parent;
    vector<int> size;
    int sz;
    
    public:
    
    dsu1(int s)
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


class dsu2
{
    vector<int> parent;
    vector<int> size;
    int sz;
    
    public:
    
    dsu2(int s)
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        int maxremove=0;
        
        sort(edges.rbegin(),edges.rend());
        
        dsu1 d1(n+1);
        dsu2 d2(n+1);
        
        int size=edges.size();
        
        int ctalice=1;
        int ctbob=1;
        
        
        for(int i=0;i<size;i++)
        {
            int u=edges[i][1];
            int v=edges[i][2];
            
            if(edges[i][0]==3)
            {
                 int flag1=0;
                 int flag2=0;
                 if(d1.findParent(u)!=d1.findParent(v))
                 {
                     d1.findUnion(u,v);
                     ctalice++;
                     flag1=1;
                 }
                
                 
                 if(d2.findParent(u)!=d2.findParent(v))
                 {
                     d2.findUnion(u,v);
                     ctbob++;
                     flag2=1;
                 }
                
                if(flag1==0 && flag2==0)
                    maxremove++;
                     
            }
            else if(edges[i][0]==2)
            {
                  
                 if(d2.findParent(u)!=d2.findParent(v))
                 {
                     d2.findUnion(u,v);
                     ctbob++;
                 }
                 else
                 {
                     maxremove++;
                 }
            }
            else
            {
                 if(d1.findParent(u)!=d1.findParent(v))
                 {
                     d1.findUnion(u,v);
                     ctalice++;
                 }
                 else
                 {
                     maxremove++;
                 }
            }
            
        }
        
        if(ctalice!=n || ctbob!=n)
            return -1;
        
        return maxremove;
        
    }
};














