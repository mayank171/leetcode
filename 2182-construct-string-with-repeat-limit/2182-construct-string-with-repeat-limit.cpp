class Solution {
public:
    string repeatLimitedString(string s, int rp) {
        
//         map<char,int,greater<int>> mp;
        
//         int l=s.length();
//         string ans="";
        
//         for(int i=0;i<l;i++)
//         {
//             mp[s[i]]++;
//         }
        

        
//         set<int> st;
//         int ind=0;
//         for(auto &it:mp)
//         {
//             int x=it.second;
//             char ch=it.first;
            
//             int ct=0;
            
            
//             while(x && !st.empty())
//             {
//                 ans[*st.begin()]=ch;
//                 st.erase(st.begin());
//                 ct++;
//                 x--;
//             }
            
//             ct=0;
            
//             while(x)
//             {
//                 if(ct<rp)
//                 {
//                     ans+=ch;
//                     ct++;
//                     ind++;
//                      x--;
//                 }
//                 else
//                 {
//                     ct=0;
//                     ans+=' ';
//                     st.insert(ind);
//                     ind++;
//                 }
               
//             }
            
//         }
        
//         for(int i=0;i<ans.size();i++)
//         {
//             if(ans[i]==' ')
//             {
//                 ans.erase(ans.begin()+i,ans.end());
//             }
//         }
        
//         return ans;
        
        
        
        map<char,int,greater<int>> mp;
        
        int l=s.length();
        string ans="";
        
        for(int i=0;i<l;i++)
        {
            mp[s[i]]++;
        }
        
       // string ans="";
        
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            char ch=it->first;
            int ct=it->second;
            
            if(ct==0)
                continue;
            
            if(ct>rp)
            {
                int ind=1;
                while(true)
                {
                    if(mp[ch]==0)
                        break;
                    if(ind>rp)
                    {
                        auto it1=it;
                        ++it1;
                        
//                         int flag=0;
                        
//                         for(auto &it1:mp)
//                         {
//                             if(it1.second>0)
//                             {
//                                 flag=1;
//                                 break;
//                             }
//                         }
                        
                        
                        if(it1!=mp.end())
                        {
                            char ch1=it1->first;
                            int ct1=it1->second;
                            
                            if(ct1<=0)
                                break;
                            
                            ans+=ch1;
                            
                            mp[ch1]--;
                            
                            if(mp[ch1]==0)
                                mp.erase(ch1);
                        }
                        else
                        {
                            break;
                        }
                        ind=1;
                    }
                    else if(ind<=rp)
                    {
                        ans+=ch;
                        mp[ch]--;
                        ind++;
                    }
                   // ind++;
                }
            }
            else
            {
                while(ct--)
                {
                    ans+=ch;
                }
            }
            cout<<ans<<endl;
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};