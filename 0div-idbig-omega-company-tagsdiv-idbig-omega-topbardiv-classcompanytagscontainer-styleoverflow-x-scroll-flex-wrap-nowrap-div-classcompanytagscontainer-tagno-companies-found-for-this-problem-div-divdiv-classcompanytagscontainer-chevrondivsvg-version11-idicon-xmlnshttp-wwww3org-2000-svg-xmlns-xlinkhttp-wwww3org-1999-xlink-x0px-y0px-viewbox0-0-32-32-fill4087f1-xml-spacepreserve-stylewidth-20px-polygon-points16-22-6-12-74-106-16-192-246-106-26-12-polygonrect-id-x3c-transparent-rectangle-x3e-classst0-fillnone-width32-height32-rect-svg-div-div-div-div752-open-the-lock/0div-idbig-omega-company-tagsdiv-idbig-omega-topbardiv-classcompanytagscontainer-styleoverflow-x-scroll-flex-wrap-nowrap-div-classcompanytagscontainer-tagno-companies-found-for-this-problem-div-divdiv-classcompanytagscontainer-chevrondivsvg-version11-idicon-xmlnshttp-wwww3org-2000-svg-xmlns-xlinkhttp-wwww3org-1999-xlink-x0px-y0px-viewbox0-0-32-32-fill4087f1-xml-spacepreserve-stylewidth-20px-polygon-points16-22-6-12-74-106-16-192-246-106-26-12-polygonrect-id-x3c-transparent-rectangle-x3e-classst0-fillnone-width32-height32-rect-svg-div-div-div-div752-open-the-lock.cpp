class Solution {
public:
    
    int solve(string &cur,int ind,string &target,set<string> &deadends)
    {
        if(ind==4)
        {
            return 0;
        }
        
        if(deadends.find(cur)!=deadends.end())
            return 1e5;
        
        if(cur[ind]==target[ind])
        {
            return solve(cur,ind+1,target,deadends);
        }
        else
        {
            return min(abs(target[ind]-cur[ind])+solve(cur,ind+1,target,deadends),abs('9'-abs(target[ind]-cur[ind]))+1+solve(cur,ind+1,target,deadends));
        }
    }
    
    int openLock(vector<string>& deadends, string target) {
        
        set<string> st;
        for(auto &it:deadends)
            st.insert(it);
        
        string cur="0000";
        
        queue<pair<string,int>> q;
        q.push({cur,0});
        
        int ans=-1;
        set<string> vis;
        
        while(!q.empty())
        {
            string cur=q.front().first;
            int moves=q.front().second;
            q.pop();
            
            if(cur==target)
            {
                ans=moves;
                break;
            }
            
            if(st.find(cur)!=st.end())
                continue;
            
            for(int i=0;i<4;i++)
            {
                if(cur[i]=='0')
                {
                    string a=cur;
                    string b=cur;
                    
                    a[i]='9';
                    if(vis.find(a)==vis.end())
                    {
                        q.push({a,moves+1});
                        vis.insert(a);    
                    }
                    
                    b[i]='1';
                    if(vis.find(b)==vis.end())
                    {
                        q.push({b,moves+1});
                        vis.insert(b);    
                    }
                }
                else if(cur[i]=='9')
                {
                    string a=cur;
                    string b=cur;
                    
                    a[i]='0';
                    if(vis.find(a)==vis.end())
                    {
                        q.push({a,moves+1});
                        vis.insert(a);
                    }
                    
                    b[i]='8';
                    if(vis.find(b)==vis.end())
                    {
                        q.push({b,moves+1});
                        vis.insert(b);        
                    }
                }
                else
                {
                    string a=cur;
                    string b=cur;
                    
                    a[i]=(((a[i]-'0')-1)+'0');
                    if(vis.find(a)==vis.end())
                    {
                        q.push({a,moves+1});
                        vis.insert(a);
                    }
                    
                    b[i]=(((b[i]-'0')+1)+'0');
                    if(vis.find(b)==vis.end())
                    {
                        q.push({b,moves+1});
                        vis.insert(b);
                    }
                }
            }
        }
        
        return ans;
    }
};










