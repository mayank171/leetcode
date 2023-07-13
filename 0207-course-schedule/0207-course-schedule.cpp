class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        int l=prerequisites.size();
        
        for(int i=0;i<l;i++)
        {
            int s,d;
            s=prerequisites[i][1];
            d=prerequisites[i][0];
            
            adj[s].push_back(d);
        }
        
        
        int n=numCourses;
        
        vector<int> indeg(n,0);
        
        
        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indeg[adj[i][j]]++;
            }
            
        }
        
        int c=0;
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
               // cout<<i<<endl;
                q.push(i);
                c++;
            }
           // cout<<indeg[i]<<endl;
        }
        
        
        
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<endl;
            q.pop();
            
            for(auto it: adj[node])
            {
                indeg[it]--;
                
                if(indeg[it]==0)
                {
                    c++;
                    q.push(it);
                }
            }
            
        }
        
        
        if(c==n)
        {
            return true;
        }
        else
            return false;
        
    }
};