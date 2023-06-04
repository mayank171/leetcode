//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            vector<int> nums;
            vector<char> opr;
            
            int l=s.length();
            
            for(int i=0;i<l;i++)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    int j=i;
                    int k=0;
                    while(j<l && s[j]>='0' && s[j]<='9')
                    {
                        k=k*10+(s[j]-'0');
                        j++;
                    }
                    nums.push_back(k);
                    i=j-1;
                }
                else
                {
                    opr.push_back(s[i]);
                }
            }
            
            reverse(nums.begin(),nums.end());
            reverse(opr.begin(),opr.end());
            
            string ans="";
            int i=0;
            int j=0;
            int flag=1;
            
            while(i<nums.size() && j<opr.size())
            {
                if(flag==1)
                {
                    string n1=to_string(nums[i]);
                    ans+=n1;    
                    i++;
                }
                else
                {
                    ans+=opr[j];
                    j++;
                }
                flag*=-1;
            }
            
            ans+=to_string(nums[nums.size()-1]);
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends