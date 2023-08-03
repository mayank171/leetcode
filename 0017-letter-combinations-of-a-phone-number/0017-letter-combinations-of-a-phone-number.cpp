class Solution {
public:
    
    void solve(string &digits,int n,map<int,vector<char>> &mp,int ind,vector<string> &ans,string &temp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return ;
        }
        
        int x=digits[ind]-'0';
        
        for(auto &it:mp[x])
        {
            temp.push_back(it);
            solve(digits,n,mp,ind+1,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n=digits.size();
        
        if(n==0)
            return {};
        
        map<int,vector<char>> mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        
        vector<string> ans;
        string temp="";
        
        solve(digits,n,mp,0,ans,temp);
        
        return ans;
    }
};