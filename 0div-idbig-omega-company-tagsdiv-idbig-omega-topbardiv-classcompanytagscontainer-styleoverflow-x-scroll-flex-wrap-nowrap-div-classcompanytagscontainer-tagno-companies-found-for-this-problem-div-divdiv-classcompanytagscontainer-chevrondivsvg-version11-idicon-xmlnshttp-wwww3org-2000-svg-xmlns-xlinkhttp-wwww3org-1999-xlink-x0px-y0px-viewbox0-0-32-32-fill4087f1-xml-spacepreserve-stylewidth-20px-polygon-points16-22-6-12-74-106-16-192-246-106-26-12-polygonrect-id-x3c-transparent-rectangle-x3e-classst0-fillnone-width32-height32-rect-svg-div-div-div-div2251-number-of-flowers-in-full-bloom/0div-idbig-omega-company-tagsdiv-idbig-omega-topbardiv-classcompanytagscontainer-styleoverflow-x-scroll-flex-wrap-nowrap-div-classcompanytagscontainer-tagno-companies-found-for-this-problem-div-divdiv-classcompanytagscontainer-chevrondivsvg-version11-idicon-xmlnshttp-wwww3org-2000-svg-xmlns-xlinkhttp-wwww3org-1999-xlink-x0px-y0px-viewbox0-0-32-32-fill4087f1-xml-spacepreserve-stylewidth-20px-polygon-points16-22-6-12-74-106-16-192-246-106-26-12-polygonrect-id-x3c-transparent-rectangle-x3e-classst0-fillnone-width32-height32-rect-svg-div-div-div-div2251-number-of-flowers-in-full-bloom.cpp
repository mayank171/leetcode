class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n= people.size();
        int m = flowers.size();
        vector<int> ans(n,0);
        vector<int> start(m); 
        vector<int> finish(m);
        for(int i=0;i<m;i++){
           start[i] = flowers[i][0];
           finish[i] = flowers[i][1];
        }
        sort(start.begin(),start.end()); 
        sort(finish.begin(),finish.end());
     
        for(int i=0;i<n;i++){
            int target = people[i];
            int s = upper_bound(start.begin(),start.end(),target)-start.begin();
            int e = lower_bound(finish.begin(),finish.end(),target)-finish.begin();
            
            ans[i] = s-e;;
        }
        return ans;
    }
};