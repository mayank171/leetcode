// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        
        map<int,int> ladder;
        map<int,int> snake;
        for(int i=0;i<2*N;i+=2)
        {
            if(arr[i]<arr[i+1])
               ladder.insert({arr[i],arr[i+1]});
            else
               snake.insert({arr[i],arr[i+1]});
        }
        
        queue<pair<int,int>> q;
        q.push({1,0});
        
        int ct=INT_MAX;
        vector<int> vis(31,0);
        vis[1]=1;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int moves=q.front().second;
            q.pop();
            
            //cout<<x<<" "<<moves<<endl;
            
            if(x==30)
            {
                ct=min(ct,moves);
                break;
            }
            
            
            for(int i=1;i<=6;i++)
            {
                int temp=x+i;
                
                if(temp>30)
                   break;
                
                if(vis[temp]==1)
                  continue;
             
                  
                auto it=ladder.find(temp);
                if(it!=ladder.end())
                {
                    
                    temp=(*it).second;
                    if(vis[temp]==1)
                      continue;
                }
                auto it1=snake.find(temp);
                if(it1!=snake.end())
                {
                    
                    temp=(*it1).second;
                    if(vis[temp]==1)
                    continue;
                }
         
                if(temp<=30)
                {
                    vis[temp]=1;
                    q.push({temp,moves+1});
                }
                // else if(temp==30)
                // {
                //     vis[temp]=1;
                //     q.push({temp,moves});
                // }
                   
            }
        }
        
        return ct;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends