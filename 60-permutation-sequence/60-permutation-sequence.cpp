class Solution {
private:
    
//     bool check(vector<char> v ,int n,string &ans,int &k)
//     {
//         if(ans.length()==n)
//         {
//             k--;
//             if(k==0)
//               return true;
//             else
//               return false;
//         }
        
        
//         for(int i=0;i<n;i++)
//         {
            
//             char ch;
//             if(v[i]!='/')
//                 ch=v[i];
//             else
//                 continue;
//             ans.push_back(ch);
//             v[i]='/';
//             if(check(v,n,ans,k))
//                 return true;
//             else
//             {
//                 v[i]=ch;
//                 ans.pop_back();
//             }
                
        
//         }
//         return false;
//     }
    
    
public:
    string getPermutation(int n, int k) {
        
//         string ans="";
        
//         int ind=0;
        
//         vector<char> v;
        
//         for(int i=1;i<=n;i++)
//         {
//             char ch=i+'0';
//             v.push_back(ch);
//         }
   
//         if(check(v,n,ans,k))
//             return ans;
//         else
//             return ans;
        
        
        vector<char> v;
        
        for(int i=1;i<=n;i++)
        {
            char ch=i+'0';
            v.push_back(ch);
        }
        
        int fact=1;
        int c=1;
        
        while(c<n)
        {
            fact*=c;
            c++;
        }
        
        int rem=fact/n;
        k--;
        string ans="";
        
        while(true)
        {
            ans+=v[k/fact];
            v.erase(v.begin()+k/fact);
            
            if(v.size()==0)
                break;
            k=k%fact;
            fact=fact/v.size();
            
        }
        
        return ans;
        
    }
};