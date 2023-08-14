//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n=nums.size();
        
        int x=0;
        for(int i=0;i<n;i++)
        {
            x^=nums[i];
        }
        
      //  cout<<x<<endl;
        
        vector<int> v1;
        vector<int> v2;
        
        int ind=-1;
        for(int i=0;i<=31;i++)
        {
            int p=x&(1<<i);
            if(p>0)
            {
                ind=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int p=nums[i]&(1<<ind);
            if(p>0)
            {
                v1.push_back(nums[i]);
            }
            else
            {
                v2.push_back(nums[i]);
            }
        }
        
        int ans1=0;
        for(auto &it:v1)
        {
            ans1^=it;
        }
        
        int ans2=0;
        for(auto &it:v2)
        {
            ans2^=it;
        }
        
        vector<int> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};













//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends