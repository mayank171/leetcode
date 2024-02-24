class dsu
{
    vector<int> parent;
    vector<int> size;
    vector<int> time;
    int sz;
    
    public:
    
    dsu(int s)
    {
        sz=s;
        for(int i=0;i<sz;i++)
        {
            parent.push_back(i);
            size.push_back(1);
            time.push_back(0);
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
            size[pu]+=size[pv];
            parent[pv]=pu;
          
        }
        else
        {
            size[pv]+=size[pu];
            parent[pu]=pv;    
        }
    }
    
    vector<int> getNode(int u)
    {
        vector<int> arr;
        for(int i=0;i<sz;i++)
        {
            if(parent[i]==u)
                arr.push_back(i);
        }
        
        return arr;
    }
};

class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[2]<=b[2])
            return true;
        return false;
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        map<int,vector<pair<int,int>>> mp;
        int nn=meetings.size();
        
        for(int i=0;i<nn;i++)
        {
            mp[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            mp[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});  
        }
        
        vector<int> ans;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,firstPerson});
        pq.push({0,0});
        vector<int> vis(n,0);    
        
        while(!pq.empty())
        {
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1)
                continue;
            
            vis[node]=1;
            ans.push_back(node);
            
            
            
            for(auto &it:mp[node])
            {
                if(t<=it.second)
                pq.push({it.second,it.first});
            }
        }
        
        return ans;
    }
};















