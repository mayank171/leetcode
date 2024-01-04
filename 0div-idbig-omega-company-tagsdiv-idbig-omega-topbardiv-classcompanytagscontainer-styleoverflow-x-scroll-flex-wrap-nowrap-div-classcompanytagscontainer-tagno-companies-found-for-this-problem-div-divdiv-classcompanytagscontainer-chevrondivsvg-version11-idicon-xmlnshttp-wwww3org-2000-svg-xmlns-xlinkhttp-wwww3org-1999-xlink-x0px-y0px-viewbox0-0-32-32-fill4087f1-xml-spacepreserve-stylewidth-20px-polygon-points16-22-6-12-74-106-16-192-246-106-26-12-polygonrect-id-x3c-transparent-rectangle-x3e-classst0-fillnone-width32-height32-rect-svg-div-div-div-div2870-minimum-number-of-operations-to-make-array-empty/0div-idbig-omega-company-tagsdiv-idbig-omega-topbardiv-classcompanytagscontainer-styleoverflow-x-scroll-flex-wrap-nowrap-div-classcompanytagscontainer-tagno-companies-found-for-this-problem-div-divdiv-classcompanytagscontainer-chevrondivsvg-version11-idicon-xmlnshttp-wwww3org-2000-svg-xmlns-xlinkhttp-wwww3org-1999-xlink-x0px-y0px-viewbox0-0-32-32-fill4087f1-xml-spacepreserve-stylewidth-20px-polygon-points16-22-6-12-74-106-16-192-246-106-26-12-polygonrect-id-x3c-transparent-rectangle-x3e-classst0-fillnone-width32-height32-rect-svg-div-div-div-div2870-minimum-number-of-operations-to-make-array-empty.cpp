class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int cnt =0;
        
        for(auto i:mp){
            int a = i.second;
            if(a==1)return -1;
            while(a%3!=0){
                a = a-2;
                cnt++;
            }
            cnt += a/3;
        }
        return cnt;
        
    }
};