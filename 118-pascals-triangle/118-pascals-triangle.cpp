class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> v(n);
    
        for(int i=0;i<n;i++)
            v[i].push_back(1);
        for(int i=1;i<n;i++)
        {
      
            for(int j=1;j<=i;j++)
            {
                if(j==i)
                {
                    v[i].push_back(v[i-1][j-1]);
                }
                else
                    v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            }
        }
        
//         for(auto &it:v)
//         {
//             for(auto &it1:it)
//                 cout<<it1<<" ";
//             cout<<endl;
//         }
        
//         vector<vector<int>> ans;
        
        return v;
        
    }
};