//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string s){
      
      long long ans=0;
      
      int n=s.length();
      
      
       if(X>Y)
       {
          stack<char> stk;
          int p1=0;
        
          for(int i=0;i<n;i++)
          {
              if(stk.empty())
              {
                  stk.push(s[i]);
              }
              else
              {
                  if(stk.top()=='p' && s[i]=='r')
                  {
                      p1++;
                      stk.pop();
                  }
                  else
                  {
                      stk.push(s[i]);
                  }
              }
          }
          
          s="";
           while(!stk.empty())
           {
               s+=stk.top();
               stk.pop();
           }
           
           reverse(s.begin(),s.end());
           
           int p2=0;
           
           for(int i=0;i<s.length();i++)
           {
              if(stk.empty())
              {
                  stk.push(s[i]);
              }
              else
              {
                  if(stk.top()=='r' && s[i]=='p')
                  {
                      p2++;
                      stk.pop();
                  }
                  else
                  {
                      stk.push(s[i]);
                  }
              }
           }
           
           long long ans= p1*1ll*X;
           ans+=p2*1ll*Y;
           
           return ans;
       }
       else
       {
           stack<char> stk;
          int p1=0;
        
          for(int i=0;i<n;i++)
          {
              if(stk.empty())
              {
                  stk.push(s[i]);
              }
              else
              {
                  if(stk.top()=='r' && s[i]=='p')
                  {
                      p1++;
                      stk.pop();
                  }
                  else
                  {
                      stk.push(s[i]);
                  }
              }
          }
          
          s="";
           while(!stk.empty())
           {
               s+=stk.top();
               stk.pop();
           }
           
           reverse(s.begin(),s.end());
           
           int p2=0;
           
           for(int i=0;i<s.length();i++)
           {
              if(stk.empty())
              {
                  stk.push(s[i]);
              }
              else
              {
                  if(stk.top()=='p' && s[i]=='r')
                  {
                      p2++;
                      stk.pop();
                  }
                  else
                  {
                      stk.push(s[i]);
                  }
              }
           }
           
           long long ans= p1*1ll*Y;
           ans+=p2*1ll*X;
           
           return ans;
       }
       
       
       
       
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends