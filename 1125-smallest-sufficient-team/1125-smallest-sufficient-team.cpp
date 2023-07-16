class Solution {
public:
    
    int solve(int req,vector<int> &vp,int ind,int cur,vector<vector<int>> &dp,vector<vector<int>> &choice)
    {
        if(cur==req)
        {
            return 0;
        }
        
        if(ind==vp.size())
        {
            return 1e5;
        }
        
        if(dp[ind][cur]!=-1)
            return dp[ind][cur];
       
        int take=1e5;
        int x=cur;
        cur=cur|vp[ind];
        take=solve(req,vp,ind+1,cur,dp,choice)+1;
        cur=x;
        int nottake=1e5;
        nottake=solve(req,vp,ind+1,cur,dp,choice);
        
        if(take<nottake)
            choice[ind][cur]=1;
        
        return dp[ind][cur]=min(take,nottake);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int req=pow(2,req_skills.size())-1;
        
        map<string,int> mp;
        int ct=0;
        
        for(auto &it:req_skills)
        {
            mp[it]=ct;
            ct++;
        }
        
        vector<int> vp;
        for(int i=0;i<people.size();i++)
        {
            int x=0;
            for(int j=0;j<people[i].size();j++)
            {
                x=(x|(1<<mp[people[i][j]]));
            }
            
            vp.push_back(x);
        }
        
        
        vector<vector<int>> dp(people.size(),vector<int>((1<<req_skills.size())+10,-1));
        vector<vector<int>> choice(people.size(),vector<int>((1<<req_skills.size())+10,-1));
        int ans=solve(req,vp,0,0,dp,choice);
        cout<<ans<<endl;
        
        vector<int> res;
        int mask=0;
        for(int i=0;i<people.size();i++)
        {
            if(choice[i][mask]==1)
            {
                res.push_back(i);
                mask|=vp[i];
            }
            if(mask==req)
                break;
        }
        
        return res;
    }
};