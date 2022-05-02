class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> v;
        
        while(label!=0)
        {
            v.push_back(label);
            label=label/2;
        }
        
        vector<int> ans;
        
        reverse(v.begin(),v.end());
        
//         ans.push_back(v[0]);
//         ans.push_back(v[1]);
        
        for(auto &it:v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int flag=-1;
        
        ans.push_back(v[v.size()-1]);
        
        int height=log2(v[v.size()-1])-1;
        
        int p;
        
        if(height%2==0)
        {
             int l=pow(2,height);
             int m=pow(2,height+1)-1;
                
             p=l+m-v[v.size()-1]/2;
        }
        else
        {
             p=v[v.size()-1];
             p=p/2;
        }
        
        while(p)
        {
            if(height&1)
            {
                int l=pow(2,height);
                int m=pow(2,height+1)-1;
                
                ans.push_back(l+m-p);
            }
            else
            {
                ans.push_back(p);
            }
            p=p/2;
            height--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};