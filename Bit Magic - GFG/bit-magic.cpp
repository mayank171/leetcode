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
    int bitMagic(int n, vector<int> &arr) {
        
        int left1=0;
        int left0=0;
        
        for(int i=0;i<n/2;i++)
        {
            if(arr[i]!=arr[n-i-1])
            {
                if(arr[i]==1)
                   left1++;
                if(arr[i]==0)
                   left0++;
            }
        }
        
        int right1=0;
        int right0=0;
        
        for(int i=n-1;i>=n/2;i--)
        {
            if(arr[i]!=arr[n-i-1])
            {
                if(arr[i]==1)
                   right1++;
                if(arr[i]==0)
                   right0++;
            }
        }
        
           return ceil((left1+left0)/2.0);
    
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends