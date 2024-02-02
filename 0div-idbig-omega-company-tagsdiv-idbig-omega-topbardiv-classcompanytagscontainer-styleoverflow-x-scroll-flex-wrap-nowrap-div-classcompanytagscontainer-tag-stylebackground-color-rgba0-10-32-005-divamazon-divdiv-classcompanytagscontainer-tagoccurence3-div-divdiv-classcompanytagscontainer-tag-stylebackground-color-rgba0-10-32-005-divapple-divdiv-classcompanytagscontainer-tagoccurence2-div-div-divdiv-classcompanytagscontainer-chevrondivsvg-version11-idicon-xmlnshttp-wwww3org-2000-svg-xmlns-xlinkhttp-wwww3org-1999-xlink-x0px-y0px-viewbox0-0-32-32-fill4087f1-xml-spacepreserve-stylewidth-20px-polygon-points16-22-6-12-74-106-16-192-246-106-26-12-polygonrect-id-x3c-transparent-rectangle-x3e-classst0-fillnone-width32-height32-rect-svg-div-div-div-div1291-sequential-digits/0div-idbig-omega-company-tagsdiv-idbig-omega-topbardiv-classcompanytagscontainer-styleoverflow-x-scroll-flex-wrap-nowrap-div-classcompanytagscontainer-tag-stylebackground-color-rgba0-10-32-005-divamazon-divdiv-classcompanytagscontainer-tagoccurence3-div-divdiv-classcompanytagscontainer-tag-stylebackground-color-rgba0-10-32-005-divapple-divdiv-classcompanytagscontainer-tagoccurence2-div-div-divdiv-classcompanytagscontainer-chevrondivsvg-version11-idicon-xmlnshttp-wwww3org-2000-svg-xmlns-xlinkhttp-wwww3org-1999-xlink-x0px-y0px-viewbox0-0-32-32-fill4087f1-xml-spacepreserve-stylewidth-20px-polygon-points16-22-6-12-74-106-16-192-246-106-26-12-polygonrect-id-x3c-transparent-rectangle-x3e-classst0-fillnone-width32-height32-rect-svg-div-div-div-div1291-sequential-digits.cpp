class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        
        for(int i=1;i<=9;i++)
        {
            int x=i;
            cout<<"x"<<x<<endl;
            int nxt=x+1;
            
            while(x<low && nxt!=10)
            {
                x=x*10+nxt;
                nxt++;
            }
            
            if(x>=low && x<=high)
               ans.push_back(x);
            
            cout<<x<<endl;
         
            while(x>=low && x<=high && nxt!=10)
            {
                x=x*10+nxt;
                nxt++;
                if(x<=high)
                   ans.push_back(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};