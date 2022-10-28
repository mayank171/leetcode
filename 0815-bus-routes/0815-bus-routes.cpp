class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& a, int source, int target) {
        
        
//         int n=routes.size();
//         map<int,vector<int>> mp;
        
//         int flagSrc=0;
//         int flagTar=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<routes[i].size();j++)
//             {
//                 if(routes[i][j]==source)
//                     flagSrc=1;
//                 if(routes[i][j]==target)
//                     flagTar=1;
                
//                 mp[routes[i][j]].push_back(i);
//             }
//         }
        
//         if(flagSrc==0 || flagTar==0)
//             return -1;
        
//         queue<int> q;
//         set<int> busStopVis;
//         set<int> busNoVis;
        
//         q.push(source);
//         busStopVis.insert(source);
//         int level=0;
        
//         while(!q.empty())
//         {
//             int size=q.size();
            
//             for(int i=0;i<size;i++)
//             {
//                 int curBusStop=q.front();
//                 q.pop();
                
//                 if(curBusStop==target)
//                     return level;
                
//                 vector<int> curBuses=mp[curBusStop];
//                 int size1=curBuses.size();
                
//                 for(int i=0;i<size1;i++)
//                 {
//                     if(busNoVis.find(curBuses[i])==busNoVis.end())
//                     {
//                         int curStops=routes[curBuses[i]].size();
//                         for(int j=0;j<curStops;j++)
//                         {
//                             if(busStopVis.find(routes[curBuses[i]][j])==busStopVis.end())
//                             {
//                                 busStopVis.insert(routes[curBuses[i]][j]);
//                                 q.push(routes[curBuses[i]][j]);
//                             }
//                         }
//                         busNoVis.insert(curBuses[i]);
//                     }
//                 }
                
//             }
//             level++;
//         }
        
//         return -1;
        
        
    int n=a.size();
        
        
    map<int,set<int>> mp;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            mp[a[i][j]].insert(i);
        }
    }
    
//     for(auto &it:mp)
//     {
//         cout<<it.first<<"-> ";
//         for(auto &it1:it.second)
//         {
//             cout<<it1<<" ";
//         }
//         cout<<endl;
//     }
    
    queue<pair<int,int>> q;
    q.push({source,0});
    
    int ans=-1;
    
    set<int> explored;
    
    set<int> vis;
    vis.insert(source);
    
    while(!q.empty())
    {
        int stop=q.front().first;
        int numstop=q.front().second;
        q.pop();
        
        if(stop==target)
        {
            ans=numstop;
            break;
        }
        
        for(auto &it:mp[stop])
        {
            if(explored.find(it)==explored.end())
            {
                int flag=0;
                for(int j=0;j<a[it].size();j++)
                {
                    if(vis.find(a[it][j])==vis.end())
                    {
                        flag=1;
                        q.push({a[it][j],numstop+1});
                        vis.insert(a[it][j]);
                    }
                }
                if(flag==1)
                   explored.insert(it);
            }
        }
    }
    
    return ans;
        
        
        
        
        
        
        
    }
};