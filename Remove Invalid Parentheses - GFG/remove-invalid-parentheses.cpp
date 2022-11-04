//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
  
    void solve(string &s,int ind,int open,int close,set<string> &ans,string &temp,int n)
    {
        if(ind==n)
        {
            if(open==0 && close==0)
            {
                ans.insert(temp);
            }
            return ;
        }
        
        if(s[ind]==')' && close>0)
        {
            solve(s,ind+1,open,close-1,ans,temp,n);
            temp.push_back(')');
            solve(s,ind+1,open,close,ans,temp,n);
            temp.pop_back();
        }
        else if(s[ind]=='(' && open>0)
        {
            solve(s,ind+1,open-1,close,ans,temp,n);
            temp.push_back('(');
            solve(s,ind+1,open,close,ans,temp,n);
            temp.pop_back();
        }
        else
        {
            temp.push_back(s[ind]);
            solve(s,ind+1,open,close,ans,temp,n);
            temp.pop_back();
        }
    }
    
    bool isvalid(string s)
    {
        stack<char> stk;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                while(!stk.empty() && stk.top()!='(')
                {
                    stk.pop();
                }
                
                if(!stk.empty())
                   stk.pop();
                
            }
            else
            {
                stk.push(s[i]);
            }
        }
        
        int flag=0;
        while(!stk.empty())
        {
            if(stk.top()=='(')
               flag++;
            else if(stk.top()==')')
               flag--;
            stk.pop();
        }
        
        if(flag==0)
           return true;
        return false;
    }
  
    vector<string> removeInvalidParentheses(string s) {
        
        int n=s.length();

        stack<pair<char,int>> stk;

        unordered_set<int> pos;

        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                while(!stk.empty() && stk.top().first!='(')
                {
                    stk.pop();
                }

                if(stk.empty())
                {
                    pos.insert(i);
                }
                else
                {
                    stk.pop();
                }
            }
            else{
                stk.push({s[i],i});
            }
        }

        while(!stk.empty())
        {
            if(stk.top().first=='(')
                pos.insert(stk.top().second);
            stk.pop();
        }

        int open=0;
        int close=0;
        for(auto &it:pos)
        {
            if(s[it]==')')
              close++;
            else
              open++;
        }
        

        set<string> ans;
        string temp="";
        
        solve(s,0,open,close,ans,temp,n);
        
        vector<string> res;
        
        
        
        for(auto &it:ans)
            if(isvalid(it))
               res.push_back(it);
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends