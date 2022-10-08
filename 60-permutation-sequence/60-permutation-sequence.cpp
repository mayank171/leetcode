class Solution {
private:
    
    
public:
    string getPermutation(int n, int k) {
        
        
        string ans="";
        
        vector<int> nums;
        int fact=1;
        
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
            fact=fact*i;
        }
        
        nums.push_back(n);
        
        k--;
        
        while(true)
        {
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
        
            if(nums.size()==0)
                break;
            k=k%fact;
            fact=fact/nums.size();
        }
        
        return ans;
        
    }
};