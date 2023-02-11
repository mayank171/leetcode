//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int nums[],int n)
	{
	    
        for(int i=0;i<n/2;i++)
        {
            int x=nums[i];
            int y=nums[i+n/2];

            x=(x<<10);
          //  cout<<x<<endl;
            x=x|y;
            nums[i]=x;
           // cout<<nums[i]<<endl;
        }

        int ind=n-1;
        for(int i=n/2-1;i>=0;i--)
        {
            int x=(nums[i]>>10);
            int p=x;
            x=(x<<10);
            int y=nums[i]^x;
           // cout<<p<<" "<<y<<endl;
            nums[ind]=y;
            nums[ind-1]=p;
            ind-=2;
        }

        return ;
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
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends