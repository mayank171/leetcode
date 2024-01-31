class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        
        int n=v.size();
        
        stack<pair<int,int>> stk;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            if(!stk.empty() && stk.top().first<v[i])
            {
                while(!stk.empty() && stk.top().first<v[i])
                {
                    ans[stk.top().second]=i-stk.top().second;
                    stk.pop();
                }
                stk.push({v[i],i});
            }
            else if(stk.empty())
            {
                stk.push({v[i],i});
            }
            else
            {
                stk.push({v[i],i});
            }
        }
        
        while(!stk.empty())
        {
            ans[stk.top().second]=0;
            stk.pop();
        }
        
        return ans;
    }
};