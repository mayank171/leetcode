class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        
        long long ans=0;
        int n=cost.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        
        vector<int> vis(n,0);
        
        for(int i=0;i<c;i++)
        {
            pq1.push({cost[i],i});
           // vis[i]=1;
        }
        
        for(int i=n-1;i>=n-c;i--)
        {
            pq2.push({cost[i],i});
           // vis[i]=1;
        }
        
        int i=c;
        int j=n-c-1;
        while(k)
        {
     //       cout<<pq1.size()<<" "<<pq2.size()<<" "<<i<<" "<<j<<"-"<<k<<endl;
            while(pq1.size()>0 && vis[pq1.top().second]==1)
            {
                pq1.pop();
                while(i<n)
                {
                    if(vis[i]==0)
                    {
                        pq1.push({cost[i],i});
                    //    vis[i]=1;
                        break;
                    }
                    i++;
                }
            }
            
            while(pq2.size()>0 && vis[pq2.top().second]==1)
            {
                pq2.pop();
                while(j>=0)
                {
                    if(vis[j]==0)
                    {
                        pq2.push({cost[j],j});
                     //   vis[j]=1;
                        break;
                    }
                    j--;
                }
            }
            
            if(pq1.size()==0 || pq2.size()==0)
                break;
            
            if(pq1.top().first<=pq2.top().first)
            {
                ans+=pq1.top().first;
      //          cout<<"1"<<" "<<pq1.top().first<<endl;
                vis[pq1.top().second]=1;
                pq1.pop();
                k--;
                
                if(pq1.size()<c)
                {
                    while(i<n)
                    {
                        if(vis[i]==0)
                        {
                            pq1.push({cost[i],i});
                            i++;
                        //    vis[i]=1;
                            break;
                        }
                        i++;
                    }
                }
            }
            else
            {
                ans+=pq2.top().first;
      //         cout<<"2"<<" "<<pq2.top().first<<endl;
                vis[pq2.top().second]=1;
                pq2.pop();
                k--;
                
                if(pq2.size()<c)
                {
                    while(j>=0)
                    {
                        if(vis[j]==0)
                        {
                            pq2.push({cost[j],j});
                            j--;
                         //   vis[j]=1;
                            break;
                        }
                        j--;
                    }
                }
            }
        }
        
        while(k && pq1.size()>0)
        {
            if(vis[pq1.top().second]==0)
            {
                ans+=pq1.top().first;
                pq1.pop();
                k--;    
            }
            else
            {
                pq1.pop();
            }
        }
        
        while(k && pq2.size()>0)
        {
            if(vis[pq2.top().second]==0)
            {
                ans+=pq2.top().first;
                pq2.pop();
                k--;    
            }
            else
            {
                pq2.pop();
            }
        }
        
        
        
        return ans;
        
    }
};