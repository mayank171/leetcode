//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        
        sort(v.rbegin(),v.rend());
        
        if(v[0]>2*(v[1]+v[2]))
        {
            int ans=0;
            while(true)
            {
                sort(v.rbegin(),v.rend());
                v[0]-=2;
                if(v[1]>0)
                {
                    v[1]--;
                    ans+=3;
                }
                else if(v[2]>0)
                {
                    v[2]--;
                    ans+=3;
                }
                else
                {
                    if(v[0]>=1)
                       return -1;
                    else
                    {
                       ans+=2;
                       break;
                    }
                }
            }
            
            return ans;
        }
        else
        {
            int ans=0;
            while(true)
            {
                sort(v.rbegin(),v.rend());
                // for(auto &it:v)
                //   cout<<it<<endl;
             //   return v[0];
                
                if(v[0]<2*(v[1]+v[2]) && v[0]>0 && v[1]>0 && v[2]>0)
                {
                    v[0]--;
                    v[1]--;
                    v[2]--;
                    ans+=3;
                }
                else
                {
                    if(v[0]<2)
                    {
                        ans+=v[0];
                        ans+=v[1];
                        ans+=v[2];
                        break;
                    }
                    v[0]-=2;
                    if(v[1])
                    {
                        v[1]--;
                        ans+=3;
                    }
                    else if(v[2])
                    {
                        v[2]--;
                        ans+=3;
                    }
                    else
                    {
                        if(v[0]==0)
                        {
                            ans+=2;
                            break;
                        }
                        else
                            return -1;
                    }
                    
                    
                }
                // else
                //   break;
                   
              //  cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
            }
            
            
            return ans;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends