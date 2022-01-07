class Solution {
    
private:
    void subsets(vector<int> &nums,int ind,vector<int> &temp,vector<vector<int>> &ans,int N)
    {
        if(ind==N)
        {
            ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[ind]);
        subsets(nums,ind+1,temp,ans,N);
        temp.pop_back();
        subsets(nums,ind+1,temp,ans,N);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
//         int N=nums.size();
        
//         int max=*max_element(nums.begin(),num.end());
        
//         int p=(int)log2(max);
        
//         int maxbits=(int)pow(p,2);
        
//         vector<int> bitOne(N,0);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        int ind=0;
        
        int N=nums.size();
        
        subsets(nums,ind,temp,ans,N);
        
        int size=ans.size();
        
        int maxOR=0;
        
        int ct=0;
        
        for(int i=0;i<N;i++)
        {
            maxOR=maxOR|nums[i];
        }
        
        cout<<maxOR<<endl;
        
        
        for(int i=0;i<size-1;i++)
        {
            int maxor=0;
            for(int j=0;j<ans[i].size();j++)
            {
                maxor=maxor|ans[i][j];
            }
            if(maxor==maxOR)
                ct++;
        }
        
        return ct;
        
        
        
    }
};