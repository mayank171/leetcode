//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int,int> mp1;
        vector<int> v(N);    
        for(int i=N-1;i>=0;i--)
        {
            mp1[A[i]]++;
            v[i]=mp1[A[i]];
        }
        
        vector<int> ans;
        
        for(int i=0;i<num;i++)
        {
            int l=Q[i][0];
            int r=Q[i][1];
            int k=Q[i][2];
            
            int ctr=0;
            for(int j=l;j<=r;j++)
            {
                if(v[j]==k)
                {
                    ctr++;
                }
            }
            
            ans.push_back(ctr);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends