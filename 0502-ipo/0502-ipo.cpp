class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n=profits.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        
        
        sort(v.begin(),v.end());
        for(auto &it:v)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        int ans=0;
        priority_queue<pair<int,int>> pq;
        
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i].first<=w)
            {
                ind=i;
                pq.push({v[i].second,v[i].first});
            }
        }
        
        while(k && !pq.empty())
        {
            if(k==0)
                break;
            int profit=pq.top().first;
            int capital=pq.top().second;
          //  cout<<profit<<" - "<<capital<<endl;
            w+=profit;
          //  cout<<w<<" + "<<ind<<endl;
            k--;
            pq.pop();
            
            for(int i=ind+1;i<n;i++)
            {
                if(v[i].first<=w)
                {
                    pq.push({v[i].second,v[i].first});
                }
                else
                {
                 //   cout<<i-1<<"_"<<endl;
                    ind=i-1;
                    break;
                }
                
                if(i==n-1)
                {
                    ind=n;
                    break;
                }
                ind=i-1;
            }
            
            if(ind==n)
            {
                break;
            }
        }
        
        while(k && !pq.empty())
        {
            w+=pq.top().first;
            pq.pop();
            k--;
        }
        
        return w;
    }
};