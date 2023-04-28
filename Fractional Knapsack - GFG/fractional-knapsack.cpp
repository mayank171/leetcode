//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool comp(pair<double,int> a,pair<double,int> b)
    {
        if(a.first>b.first)
           return true;
        return false;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    
        vector<pair<double,int>> ratio;
        
        for(int i=0;i<n;i++)
        {
            ratio.push_back({(double)arr[i].value/(double)arr[i].weight,i});
        }
        
        sort(ratio.begin(),ratio.end(),comp);
        
        double ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(W>=arr[ratio[i].second].weight)
            {
                ans+=arr[ratio[i].second].value;
                W-=arr[ratio[i].second].weight;
            }
            else
            {
                double p=W/(double)arr[ratio[i].second].weight;
                ans+=arr[ratio[i].second].value*p;
                break;
            }
            if(W==0)
               break;
        }
        
        return ans;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends