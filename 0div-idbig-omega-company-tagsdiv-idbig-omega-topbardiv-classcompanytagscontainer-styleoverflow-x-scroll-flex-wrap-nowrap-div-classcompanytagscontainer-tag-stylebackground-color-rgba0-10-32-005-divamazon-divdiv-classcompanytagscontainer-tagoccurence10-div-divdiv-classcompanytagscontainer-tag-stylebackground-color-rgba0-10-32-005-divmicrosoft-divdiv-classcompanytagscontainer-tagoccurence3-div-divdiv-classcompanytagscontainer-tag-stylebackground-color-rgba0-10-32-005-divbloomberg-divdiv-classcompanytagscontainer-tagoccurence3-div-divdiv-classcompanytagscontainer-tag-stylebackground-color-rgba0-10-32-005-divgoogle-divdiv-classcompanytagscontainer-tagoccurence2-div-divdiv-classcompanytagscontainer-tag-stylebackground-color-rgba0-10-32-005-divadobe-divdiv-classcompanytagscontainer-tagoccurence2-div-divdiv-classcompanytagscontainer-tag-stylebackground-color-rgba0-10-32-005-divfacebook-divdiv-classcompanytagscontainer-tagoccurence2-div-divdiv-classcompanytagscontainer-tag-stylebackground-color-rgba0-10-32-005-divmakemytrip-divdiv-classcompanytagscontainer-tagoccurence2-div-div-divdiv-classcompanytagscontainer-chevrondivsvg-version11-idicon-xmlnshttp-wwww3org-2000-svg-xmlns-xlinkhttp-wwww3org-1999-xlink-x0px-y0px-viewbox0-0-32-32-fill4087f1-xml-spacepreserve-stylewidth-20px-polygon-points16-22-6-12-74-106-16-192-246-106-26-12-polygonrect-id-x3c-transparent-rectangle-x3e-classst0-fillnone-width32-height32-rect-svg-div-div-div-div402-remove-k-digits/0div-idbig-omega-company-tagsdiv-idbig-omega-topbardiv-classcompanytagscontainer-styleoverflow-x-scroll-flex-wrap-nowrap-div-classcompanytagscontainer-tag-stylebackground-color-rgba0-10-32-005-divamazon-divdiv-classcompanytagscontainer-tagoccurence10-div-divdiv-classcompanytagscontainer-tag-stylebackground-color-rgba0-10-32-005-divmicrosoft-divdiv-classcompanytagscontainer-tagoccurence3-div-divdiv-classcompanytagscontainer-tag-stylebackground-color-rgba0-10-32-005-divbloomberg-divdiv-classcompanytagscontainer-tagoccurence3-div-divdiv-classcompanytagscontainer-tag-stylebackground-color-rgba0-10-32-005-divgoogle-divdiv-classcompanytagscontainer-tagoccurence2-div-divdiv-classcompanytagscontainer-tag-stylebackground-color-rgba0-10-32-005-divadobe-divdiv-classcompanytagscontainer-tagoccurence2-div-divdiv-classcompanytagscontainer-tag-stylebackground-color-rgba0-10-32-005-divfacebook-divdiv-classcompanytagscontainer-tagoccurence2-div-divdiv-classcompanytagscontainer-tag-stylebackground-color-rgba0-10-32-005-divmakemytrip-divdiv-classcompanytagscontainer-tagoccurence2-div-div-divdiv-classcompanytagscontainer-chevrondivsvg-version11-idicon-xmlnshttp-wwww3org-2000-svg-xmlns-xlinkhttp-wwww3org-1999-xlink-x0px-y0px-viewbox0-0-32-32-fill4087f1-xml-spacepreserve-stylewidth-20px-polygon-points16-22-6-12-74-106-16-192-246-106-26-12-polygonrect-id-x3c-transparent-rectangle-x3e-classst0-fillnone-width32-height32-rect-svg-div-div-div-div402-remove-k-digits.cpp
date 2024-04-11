class Solution {
public:
    string removeKdigits(string nums, int k) {
        
        //return "";
        string ans="";
        stack<int> stk;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(nums[i]-'0');
            }
            else if(stk.top()>nums[i]-'0' && k>0)
            {
                while(!stk.empty() && stk.top()>nums[i]-'0' && k>0)
                {
                    stk.pop();
                    k--;
                }
                stk.push(nums[i]-'0');
            }
            else
            {
                stk.push(nums[i]-'0');
            }
        }
        
        while(k>0)
        {
            cout<<stk.top()<<" ";
            stk.pop();
            k--;
        }
        
        nums="";
        while(!stk.empty())
        {
            nums+=(stk.top()+'0');
            cout<<stk.top()<<" ";
            stk.pop();
        }
        
        while(nums.size()>0 && nums.back()=='0')
            nums.pop_back();
        
        reverse(nums.begin(),nums.end());
        
        if(nums.size()==0)
            return "0";
        
        return nums;
    }
};






