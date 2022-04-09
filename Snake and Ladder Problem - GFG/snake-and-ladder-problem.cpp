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
        
        // map<int,int> ladder;
        // map<int,int> snake;
        // for(int i=0;i<2*N;i+=2)
        // {
        //     if(arr[i]<arr[i+1])
        //       ladder.insert({arr[i],arr[i+1]});
        //     else
        //       snake.insert({arr[i],arr[i+1]});
        // }
        
        // queue<pair<int,int>> q;
        // q.push({1,0});
        
        // int ct=INT_MAX;
        // vector<int> vis(31,0);
        // vis[1]=1;
        
        // while(!q.empty())
        // {
        //     int x=q.front().first;
        //     int moves=q.front().second;
        //     q.pop();
            
        //     //cout<<x<<" "<<moves<<endl;
            
        //     if(x==30)
        //     {
        //         ct=min(ct,moves);
        //         break;
        //     }
            
            
        //     for(int i=1;i<=6;i++)
        //     {
        //         int temp=x+i;
                
        //         if(temp>30)
        //           break;
                
        //         if(vis[temp]==1)
        //           continue;
             
                  
        //         auto it=ladder.find(temp);
        //         if(it!=ladder.end())
        //         {
                    
        //             temp=(*it).second;
        //             if(vis[temp]==1)
        //               continue;
        //         }
        //         auto it1=snake.find(temp);
        //         if(it1!=snake.end())
        //         {
                    
        //             temp=(*it1).second;
        //             if(vis[temp]==1)
        //             continue;
        //         }
         
        //         if(temp<=30)
        //         {
        //             vis[temp]=1;
        //             q.push({temp,moves+1});
        //         }
        //         // else if(temp==30)
        //         // {
        //         //     vis[temp]=1;
        //         //     q.push({temp,moves});
        //         // }
                   
        //     }
        // }
        
        // return ct;
        
        map<int,int> ladder;
        map<int,int> snake;
        int i;
        for(i=0;i<N-1;i+=2)
        {
            ladder[arr[i]]=arr[i+1];
        }
        
        for(int j=i;j<2*N-1;j+=2)
        {
            snake[arr[j]]=arr[j+1];
        }
        
        // for(auto &it:ladder)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        // for(auto &it:snake)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        
        queue<pair<int,int>> q;
        q.push({1,0});
        
        vector<int> vis(31,0);
        
        int ans=INT_MAX;
        
        vis[1]=1;
        
        while(!q.empty())
        {
            int start=q.front().first;
            int moves=q.front().second;
            q.pop();
           // cout<<start<<endl;
            
            if(start==30)
            {
                ans=min(ans,moves);
                continue;
            }
            
            if(start>30)
            {
                continue;
            }
            
            for(int i=1;i<=6;i++)
            {
                int pos=start+i;
                
                if(pos>30)
                  continue;
                
                if(vis[pos]==1)
                {
                    continue;
                }
                if(ladder.find(pos)!=ladder.end())
                {
                    if(vis[ladder[pos]]==1)
                    continue;
                    
                    pos=ladder[pos];
                    vis[pos]=1;
                    q.push({pos,moves+1});
                }
                if(snake.find(pos)!=snake.end())
                {
                    if(vis[snake[pos]]==1)
                    continue;
                    
                    pos=snake[pos];
                    vis[pos]=1;
                    q.push({pos,moves+1});
                }
                
                vis[pos]=1;
                q.push({pos,moves+1});
                
                
            }
            
            
        }
        
        return ans;
        
        
        
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