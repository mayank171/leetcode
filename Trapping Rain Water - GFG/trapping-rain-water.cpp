//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        vector<int> prefix(n);prefix[0]=0;
        vector<int> suffix(n);suffix[n-1]=n-1;
        
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=arr[prefix[i-1]])
            {
                prefix[i]=i;
            }
            else
            {
                prefix[i]=prefix[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=arr[suffix[i+1]])
            {
                suffix[i]=i;
            }
            else
            {
                suffix[i]=suffix[i+1];
            }
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+=(min<long long>(arr[prefix[i]],arr[suffix[i]]))-arr[i];
        }
        
        return ans;
        
    }
};
























//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends