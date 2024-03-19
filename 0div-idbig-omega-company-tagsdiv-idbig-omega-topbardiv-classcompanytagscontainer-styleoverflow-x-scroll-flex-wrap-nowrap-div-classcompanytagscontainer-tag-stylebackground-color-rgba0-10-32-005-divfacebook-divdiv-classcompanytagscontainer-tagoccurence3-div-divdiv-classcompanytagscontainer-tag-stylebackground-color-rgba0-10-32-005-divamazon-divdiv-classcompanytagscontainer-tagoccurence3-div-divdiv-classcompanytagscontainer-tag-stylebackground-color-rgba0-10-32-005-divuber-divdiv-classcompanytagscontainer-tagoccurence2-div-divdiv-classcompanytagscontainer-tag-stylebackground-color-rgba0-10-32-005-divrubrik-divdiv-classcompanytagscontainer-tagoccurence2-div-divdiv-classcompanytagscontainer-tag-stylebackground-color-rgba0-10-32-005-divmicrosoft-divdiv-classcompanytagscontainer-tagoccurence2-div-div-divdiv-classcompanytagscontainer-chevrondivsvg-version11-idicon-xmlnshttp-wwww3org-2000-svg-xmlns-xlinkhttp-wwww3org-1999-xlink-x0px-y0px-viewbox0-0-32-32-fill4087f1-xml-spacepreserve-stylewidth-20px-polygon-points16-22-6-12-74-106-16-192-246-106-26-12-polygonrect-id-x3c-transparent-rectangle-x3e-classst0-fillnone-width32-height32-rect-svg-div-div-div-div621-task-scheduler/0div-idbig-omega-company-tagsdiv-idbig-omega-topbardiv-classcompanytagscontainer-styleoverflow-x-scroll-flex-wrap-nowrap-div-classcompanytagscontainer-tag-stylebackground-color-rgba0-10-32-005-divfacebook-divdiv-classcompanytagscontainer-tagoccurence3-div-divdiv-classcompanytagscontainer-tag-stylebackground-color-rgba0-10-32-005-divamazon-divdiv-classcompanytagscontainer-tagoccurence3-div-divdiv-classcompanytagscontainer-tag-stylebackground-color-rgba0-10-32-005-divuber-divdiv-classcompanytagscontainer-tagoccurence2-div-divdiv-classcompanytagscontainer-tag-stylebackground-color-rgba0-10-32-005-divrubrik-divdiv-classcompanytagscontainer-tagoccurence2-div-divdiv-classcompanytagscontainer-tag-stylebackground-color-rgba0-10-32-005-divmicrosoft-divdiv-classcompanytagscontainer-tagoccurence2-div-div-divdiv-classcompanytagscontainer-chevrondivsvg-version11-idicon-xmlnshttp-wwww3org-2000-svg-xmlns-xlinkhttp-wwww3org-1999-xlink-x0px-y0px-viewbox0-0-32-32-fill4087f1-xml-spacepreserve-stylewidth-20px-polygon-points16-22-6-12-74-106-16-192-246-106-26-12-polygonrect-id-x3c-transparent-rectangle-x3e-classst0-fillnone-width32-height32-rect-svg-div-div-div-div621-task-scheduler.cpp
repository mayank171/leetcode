class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        
        map<char,int> mp;
        for(auto &it:tasks)
        {
            mp[it]++;
        }
        
        for(auto &it:mp)
        {
            pq.push(it.second);
        }
        
        int time=0;
        
        while(true)
        {
            time++;
            if(!pq.empty())
            {
                int x=pq.top();
                pq.pop();
                
                x--;
                if(x!=0)
                   q.push({x,n+time});
              //  continue;
            }
            
            while(!q.empty() && q.front().second==time)
            {
                
                if(q.front().first!=0)
                   pq.push(q.front().first);
                q.pop();
            }
            
            if(pq.size()==0 && q.size()==0)
                break;
        }
        
        return time;
    }
};