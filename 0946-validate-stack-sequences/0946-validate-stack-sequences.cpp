class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        
        int n=pushed.size();
        int m=popped.size();
        
        stack<int> stk;
        
        int ind=0;
        
        for(int i=0;i<m;i++)
        {
            if(stk.empty() || stk.top()!=popped[i])
            {
                int flag=0;
                for(int j=ind;j<n;j++)
                {
                    if(pushed[j]==popped[i])
                    {
                        flag=1;
                        stk.push(pushed[j]);
                        ind=j+1;
                        break;
                    }
                    else
                    {
                        stk.push(pushed[j]);
                    }
                }
                
                if(flag==1)
                {
                    stk.pop();
                }
                else
                    return false;
            }
            else if(!stk.empty() && stk.top()==popped[i])
            {
                stk.pop();
            }
        }
        
        return true;
        
    }
};