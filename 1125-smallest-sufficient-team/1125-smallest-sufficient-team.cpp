class Solution {
public:
    
    int solve(vector<int> &v,int size,int n,int ind,int val,vector<vector<int>> &dp,vector<vector<int>> &taken)
    {
        if(val==pow(2,n)-1)
        {
            return 0;
        }
        
        if(ind==size)
        {
          
            return 1e5;
        }
        
        if(dp[ind][val]!=-1)
            return dp[ind][val];
        
        int take=1e5;
        take=1+solve(v,size,n,ind+1,val|v[ind],dp,taken);
        int nottake=1e5;
        nottake=solve(v,size,n,ind+1,val,dp,taken);
        
        if(take<nottake)
            taken[ind][val]=1;
        
        return dp[ind][val]=min(take,nottake);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int n=req_skills.size();
        map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[req_skills[i]]=i;
        }
        
        vector<int> v;
        int size=people.size();
        
        for(int i=0;i<size;i++)
        {
            int x=0;
            for(int j=0;j<people[i].size();j++)
            {
                x=x|(1<<mp[people[i][j]]);
            }
            v.push_back(x);
        }
        
        vector<vector<int>> dp(size,vector<int>(pow(2,n)+100,-1));
        vector<vector<int>> taken(size,vector<int>(pow(2,n)+100,0));
        
        int ans=solve(v,size,n,0,0,dp,taken);
        
        int x=0;
        vector<int> res;
        
        for(int i=0;i<size;i++)
        {
            if(taken[i][x]!=0)
            {
                res.push_back(i);
                x|=v[i];
            }
            
            if(x==pow(2,n)-1)
                break;
        }
        
        return res;
        
    }
};