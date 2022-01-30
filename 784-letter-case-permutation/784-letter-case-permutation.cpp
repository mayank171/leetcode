class Solution {
private:
    
    int x=32;
    
    void check(string &s,int ind,int l,vector<string> &ans)
    {
        cout<<ind<<endl;
        
        if(ind==l)
        {
           // cout<<s<<"vnkdv"<<endl;
            
            return ;
        }
        
        // if(s[ind]>='a' && s[ind]<='z' || s[ind]>='A' && s[ind]<='Z')
        // {
        //     ans.push_back(s);
        // }
        
        for(int i=ind;i<l;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i] = s[i] & ~x;
                cout<<s<<endl;
                check(s,i+1,l,ans);
                ans.push_back(s);
                s[i] = s[i] | x;
                
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                s[i] = s[i] | x;
                cout<<s<<endl;
                check(s,i+1,l,ans);
                ans.push_back(s);
                s[i] = s[i] & ~x;
               // check(s,i+1,l,ans);
            }
           
           
        }
        
//         if(s[l-1]>='0' && s[l-1]<='9')
//         {
//             //cout<<s<<"vnkdv"<<endl;
//             ans.push_back(s);
//             return ;
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