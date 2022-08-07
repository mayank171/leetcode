class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string str="";
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                str+=(board[i][j]+'0');
            }
        }
        
        int ind=0;
        for(int i=0;i<6;i++)
        {
            if(str[i]=='0')
            {
                ind=i;
                break;
            }   
        }
        
        string desired="123450";
        
        vector<int> adj[6];
        adj[0].push_back(1);
        adj[0].push_back(3);
        adj[1].push_back(0);
        adj[1].push_back(2);
        adj[1].push_back(4);
        adj[2].push_back(1);
        adj[2].push_back(5);
        adj[3].push_back(0);
        adj[3].push_back(4);
        adj[4].push_back(3);
        adj[4].push_back(1);
        adj[4].push_back(5);
        adj[5].push_back(2);
        adj[5].push_back(4);
        
        
        queue<string> q;
        set<string> st;
        q.push(str);
        st.insert(str);
        int level=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                string str=q.front();
               // cout<<str<<endl;
                q.pop();
                
                if(str==desired)
                    return level;
                
                
                int ind=0;
                for(int i=0;i<6;i++)
                {
                    if(str[i]=='0')
                    {
                        ind=i;
                        break;
                    }
                }
                
                for(int i=0;i<adj[ind].size();i++)
                {
                    
                    swap(str[adj[ind][i]],str[ind]);
               //     cout<<str<<endl;
                    if(st.find(str)==st.end())
                    {
                        q.push(str);
                        st.insert(str);    
                    }
                    swap(str[adj[ind][i]],str[ind]);
                }
            }
            
            
            
            level++;
        }
        
        
        return -1;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};