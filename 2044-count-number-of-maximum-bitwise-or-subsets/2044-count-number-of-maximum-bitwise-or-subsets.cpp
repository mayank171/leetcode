class Solution {
    
private:
//     int subsets(vector<int> &nums,vector<vector<int>> &ans,int N,int maxOR)
//     {
//         int size=(1<<N);
        
//         int ct=0;
//         for(int i=0;i<size;i++)
//         {
//             vector<int> temp;
//             int maxor=0;
//             for(int j=0;j<N;j++)
//             {
//                 if(i&(1<<j))
//                 {
//                     maxor|=nums[j];
//                 }
//             }
//             if(maxor==maxOR)
//                 ct++;
//         }
//         return ct;
//     }
  
    void check(int n,int &ct,vector<int> &nums,int maxor)
    {
        int size=(1<<n);
        
        for(int i=0;i<size;i++){

             int x=0;
             for(int j=0;j<n;j++)
             {
                 if(i&(1<<j))
                 {
                    x=x|(nums[j]); 
                 }
             }
            
            if(maxor==x)
                ct++;
    
        }
        
        
    }
    
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
  
        
//         vector<vector<int>> ans;
        
//         vector<int> temp;
        
//         int ind=0;
        
//         int N=nums.size();
        
//         int maxOR=0;
        
//         int ct=0;
        
//         for(int i=0;i<N;i++)
//         {
//             maxOR=maxOR|nums[i];
//         }
        
//         ct=subsets(nums,ans,N,maxOR);
        
//         int size=ans.size();
        
        
        
// //         for(int i=0;i<size-1;i++)
// //         {
// //             int maxor=0;
// //             for(int j=0;j<ans[i].size();j++)
// //             {
// //                 maxor=maxor|ans[i][j];
// //             }
// //             if(maxor==maxOR)
// //                 ct++;
// //         }
        
//         return ct;
        
        
        int n=nums.size();
        
        int max_or=0;
        
        for(int i=0;i<n;i++)
        {
            max_or|=nums[i];
        }
        
        
        int ct=0;
        
        check(n,ct,nums,max_or);
        
        return ct;
        
        
    }
};