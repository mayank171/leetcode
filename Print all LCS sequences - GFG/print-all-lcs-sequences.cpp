// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	void check(vector<vector<int>> &dp,set<string>& st,int i,int j,int n,int m,string &s,string &t,string &str)
	{
	    
	    if(i==0 || j==0)
	    {
	        reverse(str.begin(),str.end());
	        st.insert(str);
	        return ;
	    }
	    
	    if(s[i-1]==t[j-1])
	    {
	        str+=s[i-1];
	        check(dp,st,i-1,j-1,n,m,s,t,str);
	        str.pop_back();
	    }
	    else
	    {
	        check(dp,st,i-1,j,n,m,s,t,str);
	        check(dp,st,i,j-1,n,m,s,t,str);
	    }
	    
	    
	}
	
	
	vector<string> all_longest_common_subsequences(string s, string t)  
		{
		    // Code here
		    int n=s.length();
		    int m=t.length();
		    
		    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		    
		    for(int i=1;i<n+1;i++)
		    {
		        for(int j=1;j<m+1;j++)
		        {
		            if(s[i-1]==t[j-1])
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    
		  unordered_set<string> st;
		  //  string str="";
		  // // check(dp,st,n,m,n+1,m+1,s,t,str);
		    
		    
		    
		 
		  //  vector<string> ans;
		    
		  //  for(auto &it:st)
		  //  {
		  //      cout<<it<<endl;    
		  //      if(it.length()==dp[n][m])
		  //        ans.push_back(it);
		  //  }
		    
		  //  sort(ans.begin(),ans.end());
		    
		  //  return ans;
		  
		  queue<pair<string,pair<int,int>>> q;
		  
		  q.push({"",{n,m}});
		  
		  map<pair<string,pair<int,int>>,bool> mp;
		  
		  while(!q.empty())
		  {
		      string str=q.front().first;
		      int i=q.front().second.first;
		      int j=q.front().second.second;
		      q.pop();
		      
		      if(mp.find({str,{i,j}})!=mp.end())   continue;
		      mp[{str,{i,j}}]=true;
		      
		      
		      if(i==0 || j==0)
		      {
		          reverse(str.begin(),str.end());
		          st.insert(str);
		          continue;
		      }
		      
		      
		      
		      if(s[i-1]==t[j-1])
		      {
		      
		          q.push({str+s[i-1],{i-1,j-1}});
		      }
		      else
		      {
		          if(dp[i-1][j]>dp[i][j-1])
		             q.push({str,{i-1,j}});
		          else if(dp[i-1][j]<dp[i][j-1])
		             q.push({str,{i,j-1}});
		          else
		          {
		             q.push({str,{i-1,j}});
		             q.push({str,{i,j-1}});
		          }
		      }
		  }
		    
		  vector<string> ans;
		  
		  for(auto &it:st)
		  {
		      if(it.length()==dp[n][m])
		      {
		          ans.push_back(it);
		      }
		  }
		  
		  sort(ans.begin(),ans.end());
		  
		  return ans;
		   
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends