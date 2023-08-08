//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
        vector<int> left;
        left.push_back(0);
        stack<int> stk;
        stk.push(A[0]);
        
        for(int i=1;i<n;i++)
        {
            if(stk.empty())
            {
                left.push_back(0);
                stk.push(A[i]);
                continue;
            }
            if(stk.top()>=A[i])
            {
                while(!stk.empty() && stk.top()>=A[i])
                {
                    stk.pop();
                }
                
                if(stk.size()==0)
                {
                    left.push_back(0);
                }
                else
                {
                   left.push_back(stk.top());
                }
                stk.push(A[i]);
            }
            else
            {
                left.push_back(stk.top());
                stk.push(A[i]);
            }
        }
        
       // return 0;
        
        vector<int> right(n,0);
        stack<int> stk1;
        stk1.push(A[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            if(stk1.empty())
            {
                right[i]=0;
                stk1.push(A[i]);
                continue;
            }
            
            if(stk1.top()>=A[i])
            {
                while(!stk1.empty() && stk1.top()>=A[i])
                {
                    stk1.pop();
                }
                
                if(stk1.size()==0)
                {
                    right[i]=0;
                }
                else
                {
                   right[i]=stk1.top();
                }
                stk1.push(A[i]);
            }
            else
            {
                right[i]=stk1.top();
                stk1.push(A[i]);
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,abs(left[i]-right[i]));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends