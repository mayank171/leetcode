class Solution {
private:
    bool check(vector<int> &tasks,vector<vector<int>> &v,vector<int> &temp,int x,int n,int ind,int time,int ssf)
    {
        if(ind==n)
        {
            if(ssf==x)
            {
                for(int i=0;i<x;i++)
                {
                    int sum=accumulate(v[i].begin(),v[i].end(),0);
                    if(sum>time)
                        return false;
                }
                return true;
            }
            return false;
        }
        
        for(int i=0;i<x;i++)
        {
            int sum=accumulate(v[i].begin(),v[i].end(),0);
            if(sum>time)
                return false;
        }
        
        for(int i=0;i<x;i++)
        {
            if(v[i].size()==0)
            {
                v[i].push_back(tasks[ind]);
                if(check(tasks,v,temp,x,n,ind+1,time,ssf+1))
                    return true;
                v[i].pop_back();
                break;
            }
            else
            {
                v[i].push_back(tasks[ind]);
                if(check(tasks,v,temp,x,n,ind+1,time,ssf))
                    return true;
                v[i].pop_back();    
            }
        }
        return false;
    }
public:
    int minSessions(vector<int>& tasks, int time) {
        
        int n=tasks.size();
        int i;
        
        int sum=accumulate(tasks.begin(),tasks.end(),0);
        
        if(sum<=time)
            return 1;
        
        for(i=2;i<15;i++)
        {
            vector<vector<int>> v(i);
            vector<int> temp;
            bool ans=check(tasks,v,temp,i,n,0,time,0);
            
            if(ans)
                break;
        }
        return i;
        
    }
};