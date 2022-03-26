class Solution {
private:
//     void check(vector<int> &v,vector<int> &ans,int ind, unordered_set<int> &s,int &flag)
//     {
//         if(ind==v.size())
//         {
//            // cout<<"ndkvn";
//             for(int i=0;i<ans.size()-1;i++)
//             {
//                 int x=__builtin_popcount(ans[i]);
//                 int y=__builtin_popcount(ans[i+1]);
                
//                 if(abs(x-y)!=1)
//                     return ;
//             }
            
//             int x=__builtin_popcount(ans[0]);
//             int y=__builtin_popcount(ans[ans.size()-1]);
            
//             if(abs(x-y)!=1)
//                 return ;
//             else
//             {
//                 flag=1;
//                 return ;
//             }
                
//         }
        
//         if(ans.size()>2)
//         {
//             for(int i=0;i<ans.size()-1;i++)
//             {
//                 int x=__builtin_popcount(ans[i]);
//                 int y=__builtin_popcount(ans[i+1]);
                    
//                 if(abs(x-y)!=1)
//                     return ;
//             }
//         }
        
        
//         for(int i=0;i<v.size();i++)
//         {
//             if(s.find(v[i])==s.end())
//             {
//                 ans.push_back(v[i]);
//                // cout<<v[i]<<endl;
//                 s.insert(v[i]);
//                 check(v,ans,ind+1,s,flag);
                
//                 if(flag==1)
//                 {
//                     return ;
//                 }
                
//                 ans.pop_back();
//                 s.erase(v[i]);
    
//             }
//         }
//     }
    
    void check(vector<int> &ans,int n)
    {
        if(n==1)
        {
            ans.push_back(0);
            ans.push_back(1);
            return ;
        }
        
        check(ans,n-1);
        
        int sz=ans.size();
        
        for(int i=ans.size()-1;i>=0;i--)
        {
            int x=sz+ans[i];
            ans.push_back(x);
        }
        
    }
    
public:
    vector<int> grayCode(int n) {
        
//         vector<int> ans;
        
//         vector<int> v;
        
//         int size=pow(2,n);
        
//         unordered_set<int> s;
//         int flag=0;
        
//         for(int i=0;i<size;i++)
//         {
//             v.push_back(i);
//         }
        
//         int ind=0;
        
//         check(v,ans,ind,s,flag);
        
//         return ans;
        
        vector<int> ans;
        
        
        
        check(ans,n);
        
        return ans;
        
    }
};