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
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(word[i]))
            {
                newnode->put(word[i],new node());
            }
            
            newnode=newnode->get(word[i]);
        }
        
        newnode->setFlag();
    }
    
    string prefix(string word)
    {
        node* newnode=root;
        int l=word.length();
        
        string s="";
        
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(word[i]))
            {
                 
                 break;
            }
            newnode=newnode->get(word[i]);
            s+=word[i];
            if(newnode->getFlag())
                return s;
         
        }

            return "";
    }
  
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        trie t;
        
        vector<string> s;
        
        int n=dictionary.size();
        
        int l=sentence.length();
        
       // map<string,int> m;
        
        string str="";
        for(int i=0;i<l;i++)
        {
            if(sentence[i]!=' ')
                str+=sentence[i];
            else
            {
                s.push_back(str);
                //m[str]++;
                str="";
            }
        }
        s.push_back(str);
 
        for(int i=0;i<n;i++)
        {
        
            t.insert(dictionary[i]);
        }
        
        
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            string p=t.prefix(s[i]);
            if(p.length()==0)
                ans+=s[i];
            else
                ans+=p;
            ans+=' ';
        }
        
        
        // for(int i=0;i<s.size();i++)
        // {
        //     s[i]=t.find(s[i]);
        //     ans+=s[i];
        //     ans+=' ';
        // }
        
        ans.pop_back();
        
        return ans;
        
        
        
        
        
        
//         int sl=sentence.size();
        
//         vector<string> s;
        
//         for(int i=0;i<sl;i++)
//         {
//               string str="";
//               while(sentence[i]!=' ' && i<sl)
//               {
//                   str=str+sentence[i];
//                   i++;
//               }
//               s.push_back(str);
//         }
        
       
        
//         for(int i=0;i<s.size();i++)
//         {
//             for(int j=0;j<dictionary.size();j++)
//                 {
//                     if(s[i].find(dictionary[j],0)==0)
//                     {
//                         s[i]=dictionary[j];
//                     }
//                 }
            
//         }
        
//         string ans="";
//         int i;
//         for(i=0;i<s.size()-1;i++)
//         {
//             cout<<s[i]<<" ";
//             ans=ans+s[i]+" ";
//         }
//         ans=ans+s[i];
        
//         return ans;
        
    }
};