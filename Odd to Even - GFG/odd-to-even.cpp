// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    string makeEven(string s)
    {
        //code here.
        int l=s.length();
        vector<int> right(l,-1);
        
        int largest=l-1;
        
        for(int i=l-2;i>=0;i--)
        {
            if((s[i]-'0')&1)
            {
                continue;
            }
            else
            {
                if(s[i]<s[largest])
                {
                    right[i]=largest;
                }
            }
        }
        
        int large=-1;
        for(int i=0;i<l;i++)
        {
            if(right[i]!=-1)
            {
                large=i;
                break;
            }
        }
        
        if(large!=-1)
        {
           swap(s[large],s[l-1]);
           return s;
        }
        else
        {
            int last=-1;
            for(int i=0;i<l-1;i++)
            {
                if((s[i]-'0')%2==0)
                {
                    last=i;
                }
            }
            
            if(last==-1)
            {
                return s;
            }
            swap(s[l-1],s[last]);
        }
        return s;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    Solution ob;
	    cout<<ob.makeEven(str)<<endl;
	}
	return 0;
}
  // } Driver Code Ends