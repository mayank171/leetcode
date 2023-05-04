class Solution {
public:
    
    bool isPossible(vector<vector<char>> &board,char ch,int ii,int jj,int n)
    {
        for(int k=0;k<n;k++)
        {
            if(board[ii][k]==ch)
                return false;
        }
        
        for(int k=0;k<n;k++)
        {
            if(board[k][jj]==ch)
                return false;
        }
        
        for(int i=3*(ii/3);i<3*(ii/3)+3;i++)
        {
            for(int j=3*(jj/3);j<3*(jj/3)+3;j++)
            {
                if(board[i][j]==ch)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solve(int i,int j,int n,vector<vector<char>> &board)
    {
        if(i==n)
        {
            for(auto &it:board)
            {
                for(auto &it1:it)
                {
                    cout<<it1<<" ";
                }
                cout<<endl;
            }
            return true;
        }
            
        
        if(j>=n)
        { 
            return solve(i+1,0,n,board);
        }
        else if(board[i][j]!='.')
        {
            return solve(i,j+1,n,board);
        }
        else
        {
            int flag=0;
            for(char ch='1';ch<='9';ch++)
            {
                 if(isPossible(board,ch,i,j,n))
                 {
                     flag=1;
                     board[i][j]=ch;
                     if(solve(i,j+1,n,board))
                         return true;
                     else
                         board[i][j]='.';
                 }
            }      
            return false;
            
            //return solve(i+1,0,n,board);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        
        solve(0,0,n,board);
        
    }
};