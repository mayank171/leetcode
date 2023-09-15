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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int,pair<int,int>>> edges;

        int n=points.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                int w=abs(x1-x2)+abs(y1-y2);

                edges.push_back({w,{i,j}});
            }
        }

        sort(edges.begin(),edges.end());

        int ans=0;

        int size=edges.size();

        dsu d(n+1);

        for(int i=0;i<size;i++)
        {
            if(d.findParent(edges[i].second.first)!=d.findParent(edges[i].second.second))
            {
                ans+=edges[i].first;
                d.findUnion(edges[i].second.first,edges[i].second.second);
            }
        }

        return ans;

    }
};















