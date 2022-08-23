class Solution {
public:
    int minMovesToSeat(vector<int>& desk, vector<int>& stu) {
        
        int n=desk.size();
        
    sort(desk.begin(),desk.end());
    sort(stu.begin(),stu.end());
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        
        ans+=abs(desk[i]-stu[i]);
    }
    
     return ans;
        
    }
};