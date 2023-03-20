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
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        
        set<int> st;
        vector<int> dist(N,0);
        dist[0]=1;
        st.insert(A[0]);
        
        for(int i=1;i<N;i++)
        {
            if(st.find(A[i])==st.end())
            {
                dist[i]=dist[i-1]+1;
                st.insert(A[i]);
            }
            else
            {
                dist[i]=dist[i-1];
            }
        }
        
        set<int> st1;
        vector<int> dist1(N,0);
        dist1[N-1]=1;
        st1.insert(A[N-1]);
        
        for(int i=N-2;i>=0;i--)
        {
            if(st1.find(A[i])==st1.end())
            {
                dist1[i]=dist1[i+1]+1;
                st1.insert(A[i]);
            }
            else
            {
                dist1[i]=dist1[i+1];
            }
        }
        
        
        vector<int> ans;
        
        for(int i=0;i<N;i++)
        {
            int left=0;
            int right=0;
            
            if(i==0)
            {
                left=0;
                right=dist1[i+1];
                ans.push_back(left-right);
            }
            else if(i==N-1)
            {
                left=dist[i-1];
                right=0;
                ans.push_back(left-right);
            }
            else
            {
                left=dist[i-1];
                right=dist1[i+1];
             //   cout<<left<<" "<<right<<endl;
                ans.push_back(left-right);
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends