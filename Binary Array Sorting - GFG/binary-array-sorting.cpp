// { Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  private:
  
     void count_sort(int arr[],int N)
     {
         int count[2]={0,0};
         
         for(int i=0;i<N;i++)
         {
             count[arr[i]]++;
         }
         
         for(int i=1;i<2;i++)
         {
             count[i]+=count[i-1];
         }
         
         int output[N];
         
         for(int i=N-1;i>=0;i--)
         {
             output[--count[arr[i]]]=arr[i];
         }
         
         for(int i=0;i<N;i++)
         {
             arr[i]=output[i];
         }
     }
    

  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
       count_sort(A,N);
    }
};

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}



  // } Driver Code Ends