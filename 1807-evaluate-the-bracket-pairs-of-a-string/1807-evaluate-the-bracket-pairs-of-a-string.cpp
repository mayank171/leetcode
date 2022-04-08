class Solution {
public:
    
//     int strcmp(string a,string b)
//     {
//         int l1=a.length();
//         int l2=b.length();
        
//         if(l1==l2)
//         {
//             for(int i=0;i<l1;i++)
//             {
//                 if(a[i]!=b[i])
//                     return -1;
//             }
//             return 0;
//         }
//         else
//         {
//             return -1;
//         }
//     }
    
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        
        int l= s.length();
        int flag=0;
        
        int size=knowledge.size();
        
        map<string,string> mp;
        
        for(int i=0;i<size;i++)
        {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        
       // unordered_map<string,string> mp1;
        
        string word="";
        
        vector<int> v;
        
        string ans="";
        
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
                flag=1;
                v.push_back(i);
                continue;
            }
            else if(s[i]==')')
            {
                auto it=mp.find(word);
                if(it!=mp.end())
                {
                   // mp1[word]=(*it).second;
                    ans+=(*it).second;
                }
                else
                {
                   // mp1[word]='?';
                    ans+="?";
                }
                
                word="";
                flag=0;
                v.push_back(i);
                continue;
            }
            
            if(flag==1)
            {
                word+=s[i];
            }
            else
            {
                ans+=s[i];
            }
        }
        
//         for(auto &it:mp1)
//         {
//             cout<<it.first<<" "<<it.second<<endl;
//         }
        
      
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         string str="";
        
//         int lk=knowledge.size();
        
//         int p=0;
//         int start=0,end=0;
//         for(int i=0;i<l;)
//         {
//             if(s[i]=='(')
//             {
//                 string brac="";
//                 p=i;
                
//                 start=p;
                
//                 p++;
                
//                 while(s[p]!=')')
//                 {
//                     brac=brac+s[p];
//                     p++;
//                 }
//                 end=p;
                
//                 cout<<brac<<end;
                
//                 int flag=0;
//                 for(int i=0;i<lk;i++)
//                 {
                    
//                     if(strcmp(brac,knowledge[i][0])==0)
//                     {
//                         str=str+knowledge[i][1];
//                         flag=1;
//                         break;
//                     }
                    
//                 }
//                 if(flag==0)
//                 {
//                     str=str+"?";  
//                 }
//                 //cout<<str;
//                 if(end+1<l)
//                    i=end+1;
//                 else 
//                     break;
//             }
//             else
//             {
//                 str=str+s[i];
//                 i++;
//             }
//         }
        
//         return str;
        
    }
};