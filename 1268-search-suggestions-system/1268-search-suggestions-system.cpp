// struct node
// {
//     node* links[26];
//     bool flag=false;
//     int ct=0;
//     vector<char> ch;
    
//     bool containsKey(char ch)
//     {
//         return (links[ch-'a']!=NULL);
//     }
    
//     void put(char ch,node* newnode)
//     {
//         links[ch-'a']=newnode;
//     }
    
//     node* get(char ch)
//     {
//         return links[ch-'a'];
//     }
    
//     void setFlag()
//     {
//         flag=true;
//     }
    
//     bool getFlag()
//     {
//         return flag;
//     }
    
//     void setCt()
//     {
//         ct++;
//     }
    
//     bool getCt()
//     {
//         return ct;
//     }
    
//     void setChar(char c)
//     {
//         ch.push_back(c);
//     }
    
//     vector<char> setChar()
//     {
//         return ch;
//     }
   
// };

// class trie
// {
//     private:
//                node* root;
//     public:
//     trie()
//     {
//         root=new node();
//     }
    
//     void insert(string word)
//     {
//         int l=word.length();
        
//         node* newnode=root;
        
//         for(int i=0;i<l;i++)
//         {
//             if(!newnode->containsKey(word[i]))
//             {
//                 newnode->put(word[i],new node());
//                 newnode->setChar(word[i]);
//             }
//             newnode->setCt();
//             newnode=newnode->get(word[i]);
            
//         }
//         newnode->setFlag();
//     }
    
//     void check(string word,vector<string> &temp)
//     {
//         node* newnode=root;
//         int l=word.length();
//         string str="";
        
//         int i;
//         while(newnode->getFlag!=true)
//         {
//             if(newnode->getCt()>1)
//             {
//                 vector<char> ch=newnode->getChar();
//                 for(int i=0;i<ch.size();i++)
//                 {
//                      newnode=newnode->get(ch[i]);
//                      str+=
//                 }
//             }
//             if(!newnode->containsKey(word[i]))
//             {
//                 return ;
//             }
//             newnode=newnode->get(word[i]);
//             str+=word[i];
            
//         }
        
        
//     }
    
// };




class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        
        
//         int N=products.size();
        
//         sort(products.begin(),products.end());
        
//         trie t;
        
//         for(int i=0;i<N;i++)
//         {
//             t.insert(products[i]);
//         }
        
//         vector<vector<string>> ans;
        
        
        
//         int l=searchWord.length();
        
//         string s="";
//         int p=0;
//         for(int i=0;i<l;i++)
//         {
//             vector<string> temp;
//             s+=searchWord[i];
            
//             t.check(s,temp);
            
//             for(int i=0;i<temp.size();i++)
//             {
//                 cout<<temp[i]<<" ";
//             }
//             cout<<endl;
//             ans.push_back(temp);
            
//         }
        
//         return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        string current="";
        vector<string> temp;
        
        vector<vector<string>> ans;
        
        sort(products.begin(),products.end());
        
        for(char ch:searchWord)
        {
            current=current+ch;
            temp.clear();
            auto ptr=lower_bound(products.begin(),products.end(),current);
           
            for(int i=0;i<3 && (ptr+i)!=products.end();i++)
            {
                string now=*(ptr+i);
                if(now.find(current)!=string::npos)
                {
                    temp.push_back(now);
                }        
            }
            ans.push_back(temp);
        }
        
        return ans;
        
        
        
        /*
        string current="";
        vector<vector<string>> ans;
        vector<string> temp;
        
        sort(products.begin(),products.end());
        
        for(int i=0;i<searchWord.length();i++)
        {
            current=current+searchWord[i];
            temp.clear();
            
            for(auto s:products)
            {
                if(s.substr(0,current.length())==current)
                {
                    temp.push_back(s);
                }
                if(temp.size()==3)
                    break;
            }
            ans.push_back(temp);
        }
        
        return ans;
        
        */
    }
};
