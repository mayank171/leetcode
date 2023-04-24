//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
         int n=arr.size();
        vector<int>ans(n),left(n),right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i]=-1;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(left[i]==-1 and right[i]==-1)ans[i]=-1;
            else if(left[i]==-1)ans[i]=right[i];
            else if(right[i]==-1)ans[i]=left[i];
            else{
                int d1=(i-left[i]);
                int d2=(right[i]-i);
                if(d1==d2){
                    if(arr[left[i]]<arr[right[i]]){
                        ans[i]=left[i];
                    }
                    else if(arr[left[i]]>arr[right[i]]){
                        ans[i]=right[i];
                    }
                    else ans[i]=left[i];
                }
                else if(d1<d2){
                    ans[i]=left[i];
                }
                else{
                    ans[i]=right[i];
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends