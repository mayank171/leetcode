// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    private:
    void check(int cur_x,int cur_y,int dest_x,int dest_y,int N,int &ct,int &ans)
    {
        queue<pair<pair<int,int>,int>> q;
        vector<int> vis(N*N,0);
        
        vis[(cur_x)*N+(cur_y)]=1;
        
        q.push({{cur_x,cur_y},0});
        
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int ctr=q.front().second;
           // cout<<ctr<<endl;
            
            q.pop();
            
            if(x==dest_x && y==dest_y)
            {
               // cout<<"eiieie";
                ans=min(ans,ctr);
                continue;
            }
            
            int dx[8]={-1,-2,-2,-1,1,2, 2, 1};
            int dy[8]={-2,-1, 1, 2,2,1,-1,-2};
            
            for(int i=0;i<8;i++)
            {
                int ind_x=x+dx[i];
                int ind_y=y+dy[i];
            
                if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<N && vis[(ind_x)*N+(ind_y)]==0)
                {
                   // cout<<"vnovnof";
                    q.push({{ind_x,ind_y},ctr+1});
                    vis[(ind_x)*N+(ind_y)]=1;
                }
            }
        }
        
       
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int cur_x=KnightPos[0];
	    int cur_y=KnightPos[1];
	    int dest_x=TargetPos[0];
	    int dest_y=TargetPos[1];
	   // cout<<cur_x<<endl;
	    int ct=0;
	    int min=INT_MAX;
	    check(cur_x-1,cur_y-1,dest_x-1,dest_y-1,N,ct,min);
	    
	    return min;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends