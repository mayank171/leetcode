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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        
        vector<int> even;
        vector<int> odd;
        
        for(int i=0;i<N;i++)
        {
            if(B[i]&1)
               odd.push_back(B[i]);
            else
               even.push_back(B[i]);
        }
     
        
        long long ans=0;
        map<long long,long long> inc;
        map<long long,long long> dec;
        
        int ind1=0;
        int ind2=0;
        
        for(int i=0;i<N;i++)
        {
            if(A[i]%2!=0)
            {
                if(ind1==odd.size())
                   return -1;
                
                if(odd[ind1]>A[i])
                   dec[abs(odd[ind1]-A[i])]++;
                else
                   inc[abs(odd[ind1]-A[i])]++;
                ind1++;
            }
            else
            {
                if(ind2==even.size())
                   return -1;
                
                
                if(even[ind2]>A[i])
                   dec[abs(even[ind2]-A[i])]++;
                else
                   inc[abs(even[ind2]-A[i])]++;
                ind2++;
                
            }
        }
        
        
        long long sum1=0;
        for(auto &it:inc)
        {
            sum1+=it.first*it.second;
        }
        
        long long sum2=0;
        for(auto &it:dec)
        {
            sum2+=it.first*it.second;
        }
        
        if(sum1==sum2)
           return sum1/2;
           
        return -1;
        
        // // if(o.size()%2!=0 || e.size()%2!=0)
        // //   return -1;
        // long long ct1=0;
        // for(auto &it:e)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        //     ans+=it.first*1ll*it.second;
        //     ct1+=it.second;
        // }
        
           
           
        // long long ct2=0;
        // for(auto &it:o)
        // {
            
        //     cout<<it.first<<" "<<it.second<<endl;
        //     ans+=it.first*1ll*it.second;
        //     ct2+=it.second;
        // }
        
        // if((ct1+ct2)%2!=0)
        //   return -1;
        
        
        // if(ans%4!=0)
        //   return -1;
        // return ans/4;
        
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
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends