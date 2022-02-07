class Solution {
private:
    void check(int o,int c,string &s,vector<string> &ans,int n)
    {
        if(o+c==2*n)
        {
            ans.push_back(s);
            return ;
        }
        
        if(o<c)
        {
            return ;
        }
        
        if(o<n)
        {
            s.push_back('(');
            check(o+1,c,s,ans,n);
            s.pop_back();
        }
        
        if(c<n)
        {
            s.push_back(')');
            check(o,c+1,s,ans,n);
            s.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        
        int o=0;
        int c=0;
        
        string s="";
        
        vector<string> ans;
        
        check(o,c,s,ans,n);
        
        return ans;
        
    }
};