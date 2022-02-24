// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  private:
    void check(vector<int> &v,int k,vector<int> &temp,vector<vector<int>> &ans,int ind,int sum)
    {
        if(ind==v.size())
        {
            if(sum==k)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        if(sum==k)
        {
            ans.push_back(temp);
            return ;
        }
        
        if(sum>k)
        {
            return ;
        }
        // if(sum+v[ind]<=k)
        // {
            sum+=v[ind];
            temp.push_back(v[ind]);
            check(v,k,temp,ans,ind,sum);
            sum-=v[ind];
            temp.pop_back();
            check(v,k,temp,ans,ind+1,sum);
        // }
        // else
        // {
        //     sum+=v[ind+1];
        //     temp.push_back(v[ind+1]);
        //     check(v,k,ans,temp,ind+1,sum);
        //     sum-=v[ind+1];
        //     temp.pop_back();
        // }
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> temp;
        int ind=0;
        int sum=0;
        
        set<int> s;
        for(auto &it:A)
        {
            s.insert(it);
        }
        
        vector<int> v;
        
        for(auto &it:s)
        {
            v.push_back(it);
        }
        
        check(v,B,temp,ans,ind,sum);
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends