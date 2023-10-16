//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class dsu
{
    public:
    vector<int> size;
    vector<int> parent;
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
    
    int getSize(int u)
    {
        int pu=findParent(u);
        return size[pu];
    }
};


class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        dsu d(n*m);
        vector<int> vis(n*m,0);
        map<pair<int,int>,int> mp;
        
        int b=2;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]==1 && vis[i*m+j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i*m+j]=1;
                    int ct=0;
                   // set<pair<int,int>> st;
                   // st.insert({i,j});
                    
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        
                        ct++;
                        mp[{ii,jj}]=b;
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==1)
                            {
                                q.push({ind_x,ind_y});
                                vis[ind_x*m+ind_y]=1;
                                d.findUnion(ii*m+jj,ind_x*m+ind_y);
                            }
                        }
                    }
                    
                    b++;
                }
            }
        }
        
        if(mp.size()==n*m)
           return n*m;
           
        // for(auto &it:mp)
        // {
        //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
        // }
        
        
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                  //  set<pair<int,int>> st;
                    unordered_set<int> cur;
                    int ans=1;
                    for(int ind=0;ind<4;ind++)
                    {
                        int ii=dx[ind]+i;
                        int jj=dy[ind]+j;
                        
                        if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==1)
                        {
                            
                              int s=d.getSize(ii*m+jj);
                       //       cout<<"size "<<s<<endl;
                              int b=mp[{ii,jj}];
                              if(cur.find(b)==cur.end())
                              {
                                  ans+=s;
                                  cur.insert(b);
                              }
                        }
                           
                    }
                    
                    maxi=max(maxi,ans);
                }
            }
        }
        
        return maxi;
        
        
    //     vector<int> vis(n*m,0);
        
    //     int dx[4]={-1,0,1,0};
    //     int dy[4]={0,1,0,-1};
        
    //     map<pair<int,int> ,pair<int,int>> mp;
    //   // map<pair<int,int> ,int> mp2;
        
    //     int b=2;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==1 && vis[i*m+j]==0)
    //             {
    //                 queue<pair<int,int>> q;
    //                 q.push({i,j});
    //                 vis[i*m+j]=1;
    //                 int ct=0;
    //                 set<pair<int,int>> st;
    //                 st.insert({i,j});
                    
    //                 while(!q.empty())
    //                 {
    //                     int ii=q.front().first;
    //                     int jj=q.front().second;
    //                     q.pop();
                        
    //                     ct++;
    //                     st.insert({ii,jj});
                        
    //                     for(int ind=0;ind<4;ind++)
    //                     {
    //                         int ind_x=dx[ind]+ii;
    //                         int ind_y=dy[ind]+jj;
                            
    //                         if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==1)
    //                         {
    //                             q.push({ind_x,ind_y});
    //                             vis[ind_x*m+ind_y]=1;
    //                         }
    //                     }
    //                 }
                    
    //                 for(auto &it:st)
    //                 {
    //                     mp[{it.first,it.second}]={ct,b};
    //                     //mp2[{it.first,it.second}]=b;
    //                 }
    //                 b++;
    //             }
    //         }
    //     }
        
    //     if(mp.size()==n*m)
    //       return n*m;
        
        
        
    //     int maxi=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==0)
    //             {
    //               //  set<pair<int,int>> st;
    //                 unordered_set<int> cur;
    //                 int ans=1;
    //                 for(int ind=0;ind<4;ind++)
    //                 {
    //                     int ii=dx[ind]+i;
    //                     int jj=dy[ind]+j;
                        
    //                     if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==1)
    //                     {
    //                      //  st.insert({ii,jj});
    //                       auto it=mp[{ii,jj}];
    //                       if(cur.find(it.second)==cur.end())
    //                       {
    //                           ans+=it.first;
    //                           cur.insert(it.second);
    //                       }
    //                     }
                           
    //                 }
                    
    //                 maxi=max(maxi,ans);
    //             }
    //         }
    //     }
        
    //     return maxi;
    }
    
    
    
    
    
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends