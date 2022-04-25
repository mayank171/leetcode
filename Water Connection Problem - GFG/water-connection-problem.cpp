// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    
    void dfs(int n,int p,vector<pair<int,int>> adj[],int start,int &end,int &mind,vector<int> &vis,int src,int &len)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it.first]==0)
            {
                mind=min(mind,it.second);
                end=it.first;
                len++;
                dfs(n,p,adj,start,end,mind,vis,it.first,len);
            }
        }
        
    }
    
    bool static comp(pair<int,pair<int,pair<int,int>>> a,pair<int,pair<int,pair<int,int>>> b)
    {
        if(a.first<b.first)
           return true;
        return false;
    }
    
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        
        int a_size=a.size();
        int b_size=a.size();
        int d_size=a.size();
        
        unordered_set<int> s1;
        
        for(int i=0;i<a_size;i++)
        {
            s1.insert(a[i]);
        }
        
        unordered_set<int> s2;
        
        for(int i=0;i<b_size;i++)
        {
            s2.insert(b[i]);
        }
        
        
        
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<a_size;i++)
        {
            adj[a[i]].push_back({b[i],d[i]});
            adj[b[i]].push_back({a[i],d[i]});
            
        }
        
        vector<int> vis(n+1,0);
        
        vector<pair<int,pair<int,pair<int,int>>>> ans;
        
        
        for(int i=0;i<n+1;i++)
        {
            if(adj[i].size()==1)
            {
                if(vis[i]==0)
                {
                    int start=i;
                    int end=i;
                    int mind=INT_MAX;
                    int len=0;
                    vector<int> temp;
                    dfs(n+1,p,adj,start,end,mind,vis,i,len);
                    // temp.push_back(start);
                    // temp.push_back(end);
                    // temp.push_back(mind);
                    // temp.push_back(len);
                   // cout<<len<<endl;
                    ans.push_back({start,{end,{mind,len}}});
                    
                }
            }
        }
        
        for(auto &it:ans)
        {
            if(s1.find(it.first)==s1.end())
            {
                swap(it.first,it.second.first);
            }
        }
        
        sort(ans.begin(),ans.end(),comp);
        
        
        
        vector<vector<int>> res;
        
        
        for(int i=0;i<ans.size();i++)
        {
            vector<int> temp;
            temp.push_back(ans[i].first);
            temp.push_back(ans[i].second.first);
            temp.push_back(ans[i].second.second.first);
            res.push_back(temp);
        }
        
        return res;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends