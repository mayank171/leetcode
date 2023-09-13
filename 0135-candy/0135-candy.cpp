class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({ratings[i],i});
        }
        
        vector<int> ans(n,-1);
        
        while(!pq.empty())
        {
            int r=pq.top().first;
            int ind=pq.top().second;
           // cout<<r<<" "<<ind<<endl;
            pq.pop();
            
            if(ind-1>=0 && ind+1<n)
            {
                if(ans[ind-1]!=-1 && ans[ind+1]!=-1)
                {
                    if(r>ratings[ind-1] && r>ratings[ind+1])
                    {
                        ans[ind]=max(ans[ind-1],ans[ind+1])+1;    
                    }
                    else if(r>ratings[ind-1])
                    {
                        ans[ind]=ans[ind-1]+1;    
                    }
                    else if(r>ratings[ind+1])
                    {
                        ans[ind]=ans[ind+1]+1;
                    }
                    else
                    {
                        ans[ind]=1;
                    }
                }
                else if(ans[ind-1]!=-1)
                {
                    if(r>ratings[ind-1])
                    {
                        ans[ind]=ans[ind-1]+1;
                    }
                    else
                    {
                        ans[ind]=1;
                    }
                }
                else if(ans[ind+1]!=-1)
                {
                    if(r>ratings[ind+1])
                    {
                        ans[ind]=ans[ind+1]+1;
                    }
                    else
                    {
                        ans[ind]=1;
                    }
                }
                else
                {
                    ans[ind]=1;
                }
            }
            else if(ind-1>=0)
            {
                if(ans[ind-1]!=-1)
                {
                    if(r>ratings[ind-1])
                    {
                        ans[ind]=ans[ind-1]+1;
                    }
                    else
                    {
                        ans[ind]=1;
                    }
                }
                else
                {
                    ans[ind]=1;
                }
            }
            else if(ind+1<n)
            {
                if(ans[ind+1]!=-1)
                {
                    if(r>ratings[ind+1])
                    {
                        ans[ind]=ans[ind+1]+1;
                    }
                    else
                    {
                        ans[ind]=1;
                    }
                }
                else
                {
                    ans[ind]=1;
                }
            }
            else
            {
                ans[ind]=1;
            }
        }
        
        for(auto &it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int sum=accumulate(ans.begin(),ans.end(),0);
        
        return sum;
    }
};