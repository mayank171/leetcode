//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    int dx[8]={-1,-1,-1,0,1,1,1,0};
	    int dy[8]={-1,0,1,1,1,0,-1,-1};
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,pair<int,int>>> q;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                for(int ind=0;ind<8;ind++)
	                {
	                    q.push({{ind,1},{i,j}});
	                }
	            }
	        }
	    }
	    
	    vector<vector<int>> ans;
	    set<pair<int,int>> st;
	    while(!q.empty())
	    {
	        int dir=q.front().first.first;
	        int ind=q.front().first.second;
	        int ii=q.front().second.first;
	        int jj=q.front().second.second;
	        
	        q.pop();
	        
	        
	        if(ind==word.size())
	        {
	           // cout<<ii<<" "<<jj<<" "<<dir<<endl;
	            int iii=ii;
	            int jjj=jj;
	            int ct=word.size()-1;
	            while(ct--)
	            {
	                iii-=dx[dir];
	            }
	            
	            ct=word.size()-1;
	            while(ct--)
	            {
	                jjj-=dy[dir];
	            }
	           // int iii=0;
	           // int jjj=0;
	           // if(dx[dir]<0)
	           // {
	           //     iii=abs(ii+dx[dir]*word.size()+1);
	           // }
	           // else if(dx[dir]>=0)
	           // {
	           //     iii=abs(ii-dx[dir]*word.size()+1);
	           // }
	            
	           // if(dy[dir]<0)
	           // {
	           //     jjj=abs(jj+dy[dir]*word.size()+1);
	           // }
	           // else
	           // {
	           //     jjj=abs(jj-dy[dir]*word.size()+1);
	           // }
    	      //      ans.push_back({iii,jjj});
    	          st.insert({iii,jjj});
    	          continue;    
	            
	        }
	        
	        int ind_x=dx[dir]+ii;
	        int ind_y=dy[dir]+jj;
	        
	        if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==word[ind])
	        {
	            q.push({{dir,ind+1},{ind_x,ind_y}});
	        }
	    }
	    
	    
	    for(auto &it:st)
	    {
	        int x=it.first;
	        int y=it.second;
	        ans.push_back({x,y});
	    }
	    return ans;
	    
	}
};













//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends