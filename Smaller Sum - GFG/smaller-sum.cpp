//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        
        map<int,long long> mp;
        
        vector<int> temp=arr;
        vector<long long> temp1(n);
       // return temp1;
        for(int i=0;i<n;i++)
        {
            temp1[i]=arr[i];
        }
        sort(temp1.begin(),temp1.end());
        sort(temp.begin(),temp.end());
        
        //return temp1;
        
        for(int i=1;i<n;i++)
        {
            temp1[i]+=temp1[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            mp[temp[i]]=temp1[i];
        }
        
        //return temp1;
        
        vector<long long> ans;
        
        for(int i=0;i<n;i++)
        {
            auto it=mp.find(arr[i]);
            if(it==mp.begin())
            {
                ans.push_back(0);
            }
            else
            {
                --it;
                pair<long long,long long> p=*it;
                long long x=p.second;
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends