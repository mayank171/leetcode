//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    int blackBox(vector<int> &v,int n,int k,long long mid)
    {
        int cur=0;
        vector<int> temp;
        int flag=-1;
        for(int i=0;i<n;i++)
        {
            if(cur<mid)
            {
                cur+=v[i];
            }
            else
            {
                temp.push_back(cur);
                i--;
                cur=0;
            }
            
            if(temp.size()==k)
            {
                flag=i+1;
                break;
            }
        }
        
        
        if(flag!=-1)
        {
            for(int i=flag;i<n;i++)
            {
                temp[temp.size()-1]+=v[i];
            }
        }
        
        
        // for(auto &it:temp)
        //   cout<<it<<" ";
        // cout<<endl;
        
        if(cur>=mid)
        {
            temp.push_back(cur);
        }
        
        if(temp.size()<k)
           return -1;
        
        int p=*min_element(temp.begin(),temp.end());
        
        return p;
    }
    
    int maxSweetness(vector<int>& v, int N, int K) {
    
        long long high=0;
        for(int i=0;i<N;i++)
        {
            high+=v[i];
        }
        
        long long low=0;
        int ans=0;
        K++;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            
            int kk=blackBox(v,N,K,mid);
            
           // cout<<mid<<" "<<kk<<endl;
            
            if(kk>=ans)
            {
                ans=max(ans,kk);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends