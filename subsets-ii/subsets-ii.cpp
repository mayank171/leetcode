class Solution {
public:
    
//     void subset(vector<int> &nums,vector<int> temp, vector<vector<int>> &ans, int ind)
//     {
//         if(ind>=nums.size())
//         {
//             auto it=find(ans.begin(),ans.end(),temp);
//             if(it==ans.end())
//             {
//                ans.push_back(temp);
//             }
//             return;
//         }
        
        
//         temp.push_back(nums[ind]);
//         subset(nums,temp,ans,ind+1);
        
//         temp.pop_back();
        
//         subset(nums,temp,ans,ind+1);
//     }
    
    
    
    
    
    
    void check(vector<int> &nums,int size,int ind,vector<vector<int>> &ans,vector<int> &temp)
    {
       
            ans.push_back(temp);
        
            
        for(int i=ind;i<size;i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            check(nums,size,i+1,ans,temp);
            temp.pop_back();
           //check(nums,size,i+1,ans,temp);
            
        }
    }
    
    
    
    
    
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        
        int ind=0;
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        
        //ans.push_back(temp);
        
        int N=nums.size();
        
        check(nums,N,ind,ans,temp);
        
        
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         sort(nums.begin(),nums.end());
        
//         vector<vector<int>> ans;
        
//         vector<int> temp;
        
//         int ind=0; 
        
//         subset(nums,temp,ans,ind);
        
//         return ans;
    }
};