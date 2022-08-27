class Solution {
public:
    
    void solve(vector<string> &words,int n,vector<char> &letters,int m,int ind,vector<int> &score,int &ans,map<char,int> &mp,int cur)
    {
        if(ind==n)
        {
            ans=max(ans,cur);
            return;
        }
        
        string str=words[ind];
        int len=str.length();
        map<char,int> mp1;
        for(int i=0;i<len;i++)
        {
            mp1[str[i]]++;
        }
        
        int flag=0;
        for(auto &it:mp1)
        {
            if(mp.find(it.first)==mp.end())
            {
                flag=1;
                break;
            }
            if(it.second<=mp[it.first])
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        
        if(flag==1)
        {
            solve(words,n,letters,m,ind+1,score,ans,mp,cur);
            return ;
        }
        
        
        int excur=cur;
        for(auto &it:mp1)
        {
            mp[it.first]-=it.second;
            excur+=it.second*(score[it.first-'a']);
        }
        
        solve(words,n,letters,m,ind+1,score,ans,mp,excur);
        
        for(auto &it:mp1)
        {
            mp[it.first]+=it.second;
        }
    
        
        solve(words,n,letters,m,ind+1,score,ans,mp,cur);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n=words.size();
        int ans=0;
        
        int m=letters.size();
        map<char,int> mp;
        
        for(int i=0;i<m;i++)
        {
            mp[letters[i]]++;
        }
        
        int cur=0;
        solve(words,n,letters,m,0,score,ans,mp,cur);
        
        return ans;
    }
};