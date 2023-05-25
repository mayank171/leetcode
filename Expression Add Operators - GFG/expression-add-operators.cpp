//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int priority(char ch)
    {
        if(ch=='*')
          return 2;
        return 1;
    }
   
    void solve(string &s,int n,int ind,int target,vector<string> &ans,vector<char> &opr,string &cur)
    {
        if(ind==n)
        {
          //  cout<<"cdsvcsd"<<endl;
            // if(cur.find("1+0*609")!=string::npos)
            //   cout<<cur<<endl;
        //    cout<<cur<<endl;
            int l=cur.length();
            vector<int> opnd;
            vector<char> oprt;
            
            stack<char> o1;
            stack<int> o2;
            
            for(int i=0;i<l;i++)
            {
                if(i+1<l && cur[i]=='0' && cur[i+1]>='0' && cur[i+1]<='9' && i-1>=0 && (cur[i-1]=='+' || cur[i-1]=='-' || cur[i-1]=='*'))
                   return ;
            }
            
            
            
            for(int i=0;i<l;i++)
            {
                if(cur[i]!='+' && cur[i]!='-' && cur[i]!='*')
                {
                    int j=i;
                   
                    int k=0;
                    while(j<l && cur[j]>='0' && cur[j]<='9')
                    {
                        k=k*10+(cur[j]-'0');
                        j++;
                    }
                  //  opnd.push_back(k); 
                    o2.push(k);
                    i=j-1;
                }
                else 
                {
                    while(o1.size()>0 && priority(cur[i])<=priority(o1.top()))
                    {
                        int x=o2.top();o2.pop();
                        int y=o2.top();o2.pop();
                        char ch=o1.top();o1.pop();
                        
                        if(ch=='+')
                           o2.push(y+x);
                        else if(ch=='-')
                           o2.push(y-x);
                        else
                           o2.push(x*y);
                    }
                    o1.push(cur[i]);
                }
            }
            
            int j=0;
            int res=0;
            
            while(o1.size()>0)
            {
                int x=o2.top();
                o2.pop();
                int y=o2.top();
                o2.pop();
                char ch=o1.top();
                o1.pop();
                
                if(ch=='-')
                {
                    o2.push(y-x);
                }
                else if(ch=='+')
                {
                    o2.push(y+x);
                }
                else
                {
                    o2.push(y*x);
                }
                
                if(o2.size()==1)
                  break;
            }
            
            
            if(o2.size()==1 && o2.top()==target)
            {
                ans.push_back(cur);
            }
            
            return ;
        }
        
        if(ind==0)
        {
            cur+=s[ind];
            solve(s,n,ind+1,target,ans,opr,cur);
            cur.pop_back();
        }
        // else if(s[ind]=='0')
        // {
        //     for(int i=0;i<3;i++)
        //     {
        //         cur+=opr[i];
        //         cur+=s[ind];
        //         solve(s,n,ind+1,target,ans,opr,cur);
        //         cur.pop_back();
        //         cur.pop_back();
        //     } 
        // }
        else
        {
            for(int i=0;i<3;i++)
            {
                cur+=opr[i];
                cur+=s[ind];
                solve(s,n,ind+1,target,ans,opr,cur);
                cur.pop_back();
                cur.pop_back();
            }    
            
                cur+=s[ind];
                solve(s,n,ind+1,target,ans,opr,cur);
                cur.pop_back();
            
        }
    }
  
    vector<string> addOperators(string S, int target) {
        
        vector<string> ans;
        int n=S.length();
        
        vector<char> opr;
        opr.push_back('+');
        opr.push_back('-');
        opr.push_back('*');
        
        string cur="";
        //cout<<"cascscdoscdsovmdsvm"<<endl;
        solve(S,n,0,target,ans,opr,cur);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends