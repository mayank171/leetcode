class Solution {
    
private:
    int mod=1e9+7;
//     int check(string &s,int start,int end)
//     {
//         if(end==start)
//             return 1;
        
//         int take=0;
//         int nottake=0;
        
//         take=check(s,start,end-1);
//         nottake=check(s,start,end-1);
        
//         return max(take,nottake);
            
//     }
    
    
public:
    int countTexts(string s) {
        
//   
        
        int n=s.length();
        
        vector<pair<int,int>> store;
        
        char ch=s[0];
        int start=0;
        int end=0;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]==ch)
            {
                end++;        
            }
            else
            {
                store.push_back({start,end});
                start=i;
                ch=s[i];
                end=i;
            }
        }
        
        store.push_back({start,end});
        
        // for(auto &it:store)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        
        int size=store.size();
        vector<int> ans;
        
        for(int i=0;i<size;i++)
        {
            int start=store[i].first;
            int end=store[i].second;
            
            if(s[start]=='9' || s[start]=='7')
            {
                    
                if(end-start==0)
                {
                    ans.push_back(1);
                       // continue;
                }
                else if(end-start==1)
                {
                    ans.push_back(2);
                  //  continue;
                }
                else if(end-start==2)
                {
                    ans.push_back(4);
                   // continue;
                }    
                else if(end-start==3)
                {
                    ans.push_back(8);
                }
                else
                {
                    int first=1;
                    int second=2;
                    int third=4;
                    int fourth=8;
                    int x=end-start;
                    int ct=4;
                    while(ct<=x)
                    {
                        int p=(first+second)%mod;
                        p=(p+third)%mod;
                        p=(p+fourth)%mod;
                        first=second;
                        second=third;
                        third=fourth;
                        fourth=p;
                        ct++;
                    }
                    ans.push_back(fourth);
                    //continue;
                }
                continue;
            }
            
            if(end-start==0)
            {
                ans.push_back(1);
                   // continue;
            }
            else if(end-start==1)
            {
                ans.push_back(2);
              //  continue;
            }
            else if(end-start==2)
            {
                ans.push_back(4);
               // continue;
            }
            else
            {
                int first=1;
                int second=2;
                int third=4;
                
                int x=end-start;
                int ct=3;
                while(ct<=x)
                {
                    int p=(first+second)%mod;
                    p=(p+third)%mod;
                    first=second;
                    second=third;
                    third=p;
                    ct++;
                }
                ans.push_back(third);
            }
            
            
        }
        
        int res=1;
        
        for(int i=0;i<ans.size();i++)
        {
            //cout<<ans[i]<<" ";
            res=(res*1ll*ans[i])%mod;
        }
        
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};