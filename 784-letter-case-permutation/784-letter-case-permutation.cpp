class Solution {
private:
    
    int x=32;
    
    void check(string &s,int ind,int l,vector<string> &ans)
    {
        if(ind==l)
        {
            return ;
        }
        
        
        if(s[ind]>='a' && s[ind]<='z')
        {
            s[ind] = s[ind] & ~x;
            //cout<<s<<endl;
            check(s,ind+1,l,ans);
            ans.push_back(s);
            s[ind] = s[ind] | x;
            check(s,ind+1,l,ans);
            
        }
        else if(s[ind]>='A' && s[ind]<='Z')
        {
            s[ind] = s[ind] | x;
            //cout<<s<<endl;
            check(s,ind+1,l,ans);
            ans.push_back(s);
            s[ind] = s[ind] & ~x;
            check(s,ind+1,l,ans);
        }
        else
        {
            check(s,ind+1,l,ans);
        }
        
//         for(int i=ind;i<l;i++)
//         {
//             if(s[i]>='a' && s[i]<='z')
//             {
//                 s[i] = s[i] & ~x;
//                 cout<<s<<endl;
//                 check(s,i+1,l,ans);
//                 ans.push_back(s);
//                 s[i] = s[i] | x;
                
//             }
//             else if(s[i]>='A' && s[i]<='Z')
//             {
//                 s[i] = s[i] | x;
//                 cout<<s<<endl;
//                 check(s,i+1,l,ans);
//                 ans.push_back(s);
//                 s[i] = s[i] & ~x;
//             }
           
           
//         }
    
    }
public:
    vector<string> letterCasePermutation(string s) {
        
        int l=s.length();
        
        vector<string> ans;
        
        int ind=0;
        
        ans.push_back(s);
        
        check(s,ind,l,ans);
        
        return ans;
        
    }
};