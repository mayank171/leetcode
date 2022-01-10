struct node
{
    node* links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch,node* newnode)
    {
        links[ch-'a']=newnode;
    }
    
    node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void setFlag()
    {
        flag=true;
    }
    
    bool getFlag()
    {
        return flag;
    }
};

class trie
{
    private:
            node* root;
    public:
            trie()
            {
                root=new node();
            }
    
            void insert(string word)
            {
                node* newnode=root;
                int l=word.length();
                
                for(int i=1;i<l;i++)
                {
                    if(word[i]!='/')
                    { 
                            if(!newnode->containsKey(word[i]))
                            {
                                newnode->put(word[i],new node());
                            }
                   
                        newnode=newnode->get(word[i]);
                    }
             
                }
             
                newnode->setFlag();
                
            }
    
           string check(string word)
           {
               node* newnode=root;
               int l=word.length();
               
               string str="";
               
               for(int i=0;i<l;i++)
               {
                   
                   if(word[i]!='/')
                   {
                       str+=word[i];
                       newnode=newnode->get(word[i]);
                       if(newnode->getFlag())
                       {
                           if(i+1<l && word[i+1]!='/')
                               continue;
                           else
                               break;
                       }
                   }
                   else
                   {
                       str+='/';
                   }
               }
               return str;
               
           }
            
    
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        int n=folder.size();
        
        trie t;
    
        
        for(int i=0;i<n;i++)
        {
            t.insert(folder[i]);
        }
        
        vector<string> ans;
        
        set<string> s;
        
        for(int i=0;i<n;i++)
        {
            s.insert(t.check(folder[i]));
            
        }
        
        
        for(auto it:s)
        {
            ans.push_back(it);
        }
        
        return ans;
        
        
//         sort(folder.begin(),folder.end());
        
        
//         vector<string> res;
        
//         res.push_back(folder[0]);
//         int i;
//         for( i=1;i<folder.size();i++)
//         {
//             string s1=res[res.size()-1]+'/';
//             string s2=folder[i].substr(0,s1.length());
            
//             if(s1!=s2)
//             {
//                 res.push_back(folder[i]);
//                // i++;
//             }
                
//         }
       
        
//         return res;
        
        
    }
};