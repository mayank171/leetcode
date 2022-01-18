
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
    
    
    bool check(string word)
    {
        node* newnode=root;

        for(int i=0;i<word.length();i++)
        {
            if(!newnode->containsKey(word[i]))
            {
                if(word[i]>='A' && word[i]<='Z')
                    return false;
                continue;
                
            }

            //moves to reference trie
            newnode=newnode->get(word[i]);
        }

        return newnode->isEnd();
    }


    
};


class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<string> s;
        
        int n=queries.size();
        
        int sz=s.size();
        
        vector<bool> ans(n);
        
        trie t;
        t.insert(pattern);
        
        for(int i=0;i<n;i++)
        {
            if(t.check(queries[i]))
                ans[i]=true;
            else
                ans[i]=false;
        }
        
        
        return ans;
    }
};