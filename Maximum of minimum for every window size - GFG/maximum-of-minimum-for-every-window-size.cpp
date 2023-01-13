//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> nse(n);
        stack<int> stk;
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && arr[stk.top()]>arr[i])
                {
                    nse[stk.top()]=i;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        
        while(!stk.empty())
        {
            int ind=stk.top();
            nse[ind]=n;
            stk.pop();
        }
        
        vector<int> pse(n);
    
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && arr[stk.top()]>arr[i])
                {
                    pse[stk.top()]=i;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        
        while(!stk.empty())
        {
            int ind=stk.top();
            pse[ind]=-1;
            stk.pop();
        }
        
        vector<int> temp;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back(nse[i]-pse[i]-1);
        }
        
        // for(auto &it:temp)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        vector<int> size(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            size[temp[i]]=max(size[temp[i]],arr[i]);
        }
        
        // for(auto &it:size)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        
        for(int i=n-1;i>0;i--)
        {
            size[i]=max(size[i],size[i+1]);
        }
        
        reverse(size.begin(),size.end());
        size.pop_back();
        reverse(size.begin(),size.end());
        
        
        return size;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends