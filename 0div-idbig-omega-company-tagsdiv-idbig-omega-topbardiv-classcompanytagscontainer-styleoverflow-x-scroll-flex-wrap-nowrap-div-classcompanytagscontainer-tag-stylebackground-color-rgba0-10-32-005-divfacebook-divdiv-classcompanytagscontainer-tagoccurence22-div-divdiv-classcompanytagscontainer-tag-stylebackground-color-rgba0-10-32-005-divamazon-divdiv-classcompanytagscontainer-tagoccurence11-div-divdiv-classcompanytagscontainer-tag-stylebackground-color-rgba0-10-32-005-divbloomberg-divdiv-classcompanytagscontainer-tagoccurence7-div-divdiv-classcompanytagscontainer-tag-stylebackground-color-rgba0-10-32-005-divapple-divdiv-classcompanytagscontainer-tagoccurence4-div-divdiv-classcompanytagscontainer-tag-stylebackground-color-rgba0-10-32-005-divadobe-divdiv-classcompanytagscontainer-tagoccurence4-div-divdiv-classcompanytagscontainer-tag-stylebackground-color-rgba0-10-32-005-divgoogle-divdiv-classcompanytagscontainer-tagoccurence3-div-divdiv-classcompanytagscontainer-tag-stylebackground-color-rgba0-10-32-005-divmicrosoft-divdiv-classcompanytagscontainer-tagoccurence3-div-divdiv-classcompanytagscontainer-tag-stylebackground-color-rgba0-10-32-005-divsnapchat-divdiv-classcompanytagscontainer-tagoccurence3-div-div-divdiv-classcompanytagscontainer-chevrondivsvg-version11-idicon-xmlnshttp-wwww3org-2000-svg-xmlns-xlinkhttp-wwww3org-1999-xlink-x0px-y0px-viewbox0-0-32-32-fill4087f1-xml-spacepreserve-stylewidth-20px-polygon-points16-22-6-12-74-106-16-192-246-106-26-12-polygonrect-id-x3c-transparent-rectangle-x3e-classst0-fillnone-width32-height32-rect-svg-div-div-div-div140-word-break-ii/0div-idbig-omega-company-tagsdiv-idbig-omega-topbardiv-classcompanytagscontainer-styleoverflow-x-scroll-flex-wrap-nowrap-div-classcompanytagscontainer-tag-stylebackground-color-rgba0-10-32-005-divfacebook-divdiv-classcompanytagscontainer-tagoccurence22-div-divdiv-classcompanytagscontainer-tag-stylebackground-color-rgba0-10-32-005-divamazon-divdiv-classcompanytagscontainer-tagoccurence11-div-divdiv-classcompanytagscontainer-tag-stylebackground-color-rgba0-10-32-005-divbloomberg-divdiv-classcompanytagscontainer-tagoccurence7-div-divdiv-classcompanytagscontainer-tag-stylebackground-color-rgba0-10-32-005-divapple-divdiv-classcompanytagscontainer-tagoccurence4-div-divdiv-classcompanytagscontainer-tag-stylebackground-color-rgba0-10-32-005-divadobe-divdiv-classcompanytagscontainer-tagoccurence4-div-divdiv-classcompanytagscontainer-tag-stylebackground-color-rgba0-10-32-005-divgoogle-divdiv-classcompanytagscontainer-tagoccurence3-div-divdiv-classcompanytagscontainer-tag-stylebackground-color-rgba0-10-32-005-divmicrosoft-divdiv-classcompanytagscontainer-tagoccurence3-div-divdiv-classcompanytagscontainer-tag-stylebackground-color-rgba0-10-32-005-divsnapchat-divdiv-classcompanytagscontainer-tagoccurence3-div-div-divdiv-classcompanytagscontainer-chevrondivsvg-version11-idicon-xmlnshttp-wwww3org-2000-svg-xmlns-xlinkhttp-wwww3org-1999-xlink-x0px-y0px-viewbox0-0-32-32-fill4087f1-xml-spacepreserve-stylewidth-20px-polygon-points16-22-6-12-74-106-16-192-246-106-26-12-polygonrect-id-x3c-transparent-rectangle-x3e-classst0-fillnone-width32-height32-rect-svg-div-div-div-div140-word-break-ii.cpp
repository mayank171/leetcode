class Solution {
public:
    
    void solve(string &s,int n,int ind,set<string> &st, string word, string &s1,vector<string> &ans,int ct)
    {
        if(ind==n)
        {
            if(s1.size()>0)
                s1.pop_back();
            if(ct==n)
                ans.push_back(s1);
            return ;
        }
        
        word+=s[ind];
        if(st.find(word)!=st.end())
        {
            ct+=word.size();
            string s2=s1;
            s1+=word+" ";
            solve(s,n,ind+1,st,"",s1,ans,ct);
            s1=s2;
            ct-=word.size();
        }
        solve(s,n,ind+1,st,word,s1,ans,ct);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        int len=wordDict.size();
        
        set<string> st;
        for(auto &it:wordDict)
            st.insert(it);
        
        vector<string> ans;
        
        string word="";
        string s1="";
        int ct=0;
        solve(s,n,0,st,word,s1,ans,ct);
        
        return ans;
    }
};