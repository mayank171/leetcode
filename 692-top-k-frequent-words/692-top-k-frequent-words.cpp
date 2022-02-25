struct node
{
    node* links[26];
    int ct=0;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,node* newnode)
    {
        links[ch-'a']=newnode;
    }
    
    node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void inc()
    {
        ct++;
    }
    
    int getCt()
    {
        return ct;
    }
};


class trie
{
    private:
        struct node* root;
    
    public:
        trie()
        {
            root=new node();
        }
        void insert(string s)
        {
            node* newnode=root;
            int l=s.length();
            
            for(int i=0;i<l;i++)
            {
                if(!newnode->containsKey(s[i]))
                {
                    newnode->put(s[i],new node());
                }
                newnode=newnode->get(s[i]);
            }
            
            newnode->inc();
        }
    
        int check(string s)
        {
            node* newnode=root;
            int l=s.length();
            
            for(int i=0;i<l;i++)
            {
                newnode=newnode->get(s[i]);
            }
            return newnode->getCt();
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        
        trie t;
        
        
        for(int i=0;i<n;i++)
        {
            t.insert(words[i]);
            
        }
        
        map<int,set<string>,greater<int>> mp;
        
        
        for(int i=0;i<n;i++)
        {
            int x=t.check(words[i]);
            //cout<<x<<endl;
            mp[x].insert(words[i]);
           // temp.insert({x,words[i]});
        }
        
        for(auto &it:mp)
        {
            for(auto &it1:it.second)
            {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        
        
        
        vector<string> ans;
        
        for(auto &it:mp)
        {
            for(auto &it1:it.second)
            {
                if(k<=0)
                    break;
                if(ans.empty())
                {
                    ans.push_back(it1);
                    k--;
                }
                else
                {
                    if(ans[ans.size()-1]==it1)
                        break;
                    else
                    {
                        ans.push_back(it1);
                        k--;
                    }
                }
            }
        }
        
        
        return ans;
        
    }
};