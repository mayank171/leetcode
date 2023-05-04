class Solution {
public:
    
    bool possible(int row,int col,vector<pair<int,int>> &temp)
    {
        int l=temp.size();
        for(int i=0;i<l;i++)
        {
            int x=temp[i].first;
            int y=temp[i].second;
            
            if(row==x || col==y || abs(row-x)==abs(col-y))
                return false;
        }
        return true;
    }
    
    void solve(int col,int n,vector<vector<string>> &ans,vector<pair<int,int>> &temp,vector<string> &str)
    {
        if(col==n)
        {
            ans.push_back(str);
            return ;
        }
            
        
        for(int i=0;i<n;i++)
        {
            if(possible(i,col,temp))
            {
                temp.push_back({i,col});
                str[i][col]='Q';
                solve(col+1,n,ans,temp,str);
                temp.pop_back();
                str[i][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> str;
        
        string s="";
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        
        for(int i=0;i<n;i++)
        {
            str.push_back(s);
        }
        
        vector<pair<int,int>> temp;
        solve(0,n,ans,temp,str);
        return ans.size();
        
    }
};