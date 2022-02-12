// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> h)
    {
        //code here
        int ct=0;
        int ct2=0;
        int n=h.size();
        int m=h[0].size();
        
        queue<pair<pair<int,int>,int>> pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(h[i][j]==1)
                {
                    ct++;
                }
                else if(h[i][j]==2)
                {
                    ct2++;
                    pq.push({{i,j},0});
                }
            }
        }
        
        int t=0;
        while(!pq.empty())
        {
            int x=pq.front().first.first;
            int y=pq.front().first.second;
            int z=pq.front().second;
            
            pq.pop();
            
            t=max(z,t);
              
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int x_ind=x+dx[ind];
                int y_ind=y+dy[ind];
                
                if(x_ind>=0 && x_ind<n && y_ind>=0 && y_ind<m && h[x_ind][y_ind]==1)
                {
                    ct--;
                    h[x_ind][y_ind]=2;
                    pq.push({{x_ind,y_ind},z+1});
                }
            }
            
        }
        
        if(ct>0)
           return -1;
        else
           return t;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends