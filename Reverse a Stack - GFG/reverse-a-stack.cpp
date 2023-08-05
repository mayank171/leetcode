//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insert(stack<int> &stk,int x)
    {
        if(stk.size()==0)
        {
            stk.push(x);
            return ;
        }
        
        int e=stk.top();
        stk.pop();
        insert(stk,x);
        stk.push(e);
    }
 
    void reverse(stack<int> &stk)
    {
        if(stk.size()==0)
           return ;
           
        int x=stk.top();
        stk.pop();
        reverse(stk);
        insert(stk,x);
       // stk.push(x);
    }

    void Reverse(stack<int> &St){
        
        if(St.size()==0 || St.size()==1)
           return ;
           
        reverse(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends