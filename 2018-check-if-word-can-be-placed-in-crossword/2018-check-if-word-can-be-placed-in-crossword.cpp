class Solution {
private:
    bool check(string str,string word)
    {
        int l1=str.length();
        int l=word.length();
        if(l1!=l)
            return false;
        int i;
        for(i=0;i<l;i++)
        {
            if(str[i]!=word[i] && str[i]!=' ')
                break;
        }
        if(i==l)
            return true;
        
        reverse(str.begin(),str.end());
        
        for( i=0;i<l;i++)
        {
            if(str[i]!=word[i] && str[i]!=' ')
                break;
        }
        if(i==l)
            return true;
        
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        int l=word.length();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                while(j<m && board[i][j]=='#')
                    j++;
                string str="";
                while(j<m && board[i][j]!='#')
                {
                    str+=board[i][j++];
                }
                if(check(str,word))
                    return true;
            }
        }
        
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                while(i<n && board[i][j]=='#')
                    i++;
                string str="";
                while(i<n && board[i][j]!='#')
                {
                    str+=board[i++][j];
                }
                if(check(str,word))
                    return true;
            }
        }
        
        return false;
        
    }
};