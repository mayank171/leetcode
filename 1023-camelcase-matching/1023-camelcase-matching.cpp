
struct node
{
    node* links[58];
    bool flag=false;

    bool containsKey(char ch)
    {
        return (links[ch-'A']!=NULL);
    }

    void put(char ch,node* newnode)
    {
        links[ch-'A']=newnode;
    }

    node* get(char ch)
    {
        return links[ch-'A'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};


// class trie
// {
// private:
//     node* root;
// public:

//     //initialize data structure here
//     trie()
//     {
//         root=new node();
//     }

//     //insert a word into trie
//     //O(length of word)
//     void insert(string word)
//     {
//         node* newnode=root;
//         int l=word.length();

//         for(int i=0;i<l;i++)
//         {
//             if(!newnode->containsKey(word[i]))
//             {
//                 newnode->put(word[i],new node());
//             }

//             //moves to reference trie
//             newnode=newnode->get(word[i]);
//         }

//         newnode->setEnd();
//     }
    
    
//     bool check(string word)
//     {
//         node* newnode=root;

//         for(int i=0;i<word.length();i++)
//         {
//             if(!newnode->containsKey(word[i]))
//             {
//                 if(word[i]>='A' && word[i]<='Z')
//                     return false;
//                 continue;
                
//             }

//             //moves to reference trie
//             newnode=newnode->get(word[i]);
//         }

//         return newnode->isEnd();
//     }
    
    
//     bool check(stirng word)
//     {
//         node* newnode=root;
        
//         for(int i=0;i<word.length();i++)
//         {
//             if(!newnode->containsKey(word[i]))
//             {
//                 if(word[i]>='A' && word[i])
//             }
//         }
//     }


    
// };



// struct node
// {
//     node* links[58];
//     bool flag=false;

//     bool containsKey(char ch)
//     {
//         return (links[ch-'A']!=NULL);
//     }

//     void put(char ch,node* newnode)
//     {
//         links[ch-'A']=newnode;
//     }

//     node* get(char ch)
//     {
//         return links[ch-'A'];
//     }

//     void setEnd()
//     {
//         flag=true;
//     }

//     bool isEnd()
//     {
//         return flag;
//     }
// };


class trie
{
private:
    node* root;
public:

    //initialize data structure here
    trie()
    {
        root=new node();
    }

    //insert a word into trie
    //O(length of word)
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

            //moves to reference trie
            newnode=newnode->get(word[i]);
        }

        newnode->setEnd();
    }
    
    
//     bool check(string word)
//     {
//         node* newnode=root;

//         for(int i=0;i<word.length();i++)
//         {
//             if(!newnode->containsKey(word[i]))
//             {
//                 if(word[i]>='A' && word[i]<='Z')
//                     return false;
//                 continue;
                
//             }

//             //moves to reference trie
//             newnode=newnode->get(word[i]);
//         }

//         return newnode->isEnd();
//     }
    
    
    bool check(string word,string pattern)
    {
        node* newnode=root;
        
        int ind=0;
        
        for(int i=0;i<word.length();i++)
        {
        
            if(word[i]>='A' && word[i]<='Z')
            {
                if(ind<pattern.length() && word[i]==pattern[ind])
                {
                    ind++;
                }
                else if(ind<pattern.length() && pattern[ind]>='A' && pattern[ind]<='Z')
                {
                    return false;
                }
                else if(ind>=pattern.length())
                {
                    return false;
                }
            }
            else if(word[i]>='a' && word[i]<='z')
            {
                if(ind<pattern.length() && word[i]==pattern[ind])
                {
                    ind++;
                }
                else if(ind<pattern.length() && pattern[ind]>='a' && pattern[ind]<='z')
                {
                    //return false;
                }
                 
            }
           // cout<<"found";
            newnode=newnode->get(word[i]);
              
        }
        
        if(ind<pattern.length())
            return false;
        return true;
    }


    
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
//         vector<string> s;
        
//         int n=queries.size();
        
//         int sz=s.size();
        
//         vector<bool> ans(n);
        
//         trie t;
//         t.insert(pattern);
        
//         for(int i=0;i<n;i++)
//         {
//             if(t.check(queries[i]))
//                 ans[i]=true;
//             else
//                 ans[i]=false;
//         }
        
        
//         return ans;
        
        int size=queries.size();
        trie t;
       
        vector<bool> ans(size,false);
        
        for(int i=0;i<size;i++)
        {
            t.insert(queries[i]);
        }
        
        for(int i=0;i<size;i++)
        {
            bool p=t.check(queries[i],pattern);
            ans[i]=p;
           // cout<<endl;
        }
        
        return ans;
    }
};