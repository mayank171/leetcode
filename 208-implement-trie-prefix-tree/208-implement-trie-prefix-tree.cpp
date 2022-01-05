struct Node
{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL); 
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    bool getFlag()
    {
        return flag;
    }
    
    void setFlag()
    {
        flag=true;
    }
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* newnode=root;
        int l=word.length();
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(word[i]))
            {
                newnode->put(word[i],new Node());
            }
            newnode=newnode->get(word[i]);
        }
        newnode->setFlag();
    }
    
    bool search(string word) {
        Node* newnode=root;
        int l=word.length();
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(word[i]))
            {
                return false;
            }
            newnode=newnode->get(word[i]);
        }
        return newnode->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* newnode=root;
        int l=prefix.length();
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(prefix[i]))
            {
                return false;
            }
            newnode=newnode->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */