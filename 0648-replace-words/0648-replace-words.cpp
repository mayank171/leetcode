struct Node
{
    struct Node* freq[26];
    int flag;
};

class Trie
{
    private:
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(string word)
    {
        Node* node=root;
        int l=word.size();
        for(int i=0;i<l;i++)
        {
            if(node->freq[word[i]-'a']==NULL)
            {
                node->freq[word[i]-'a']=new Node();
            }
            node=node->freq[word[i]-'a'];
        }
        
        node->flag=1;
    }
    
    string check(string word)
    {
        Node* node=root;
        int l=word.size();
        string res="";
        for(int i=0;i<l;i++)
        {
            if(node->freq[word[i]-'a']!=NULL)
            {
                res+=word[i];
                node=node->freq[word[i]-'a'];
            }
            else
                break;
            
            if(node->flag==1)
                break;
        }
        
        if(node->flag==0)
            return "";
        return res;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        
        Trie t;
        for(int i=0;i<dict.size();i++)
        {
            t.insert(dict[i]);
        }
        
        int n=sentence.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            string str="";
            int j=i;
            while(j<n && sentence[j]!=' ')
            {
                str+=sentence[j];
                j++;
            }
            
            string res=t.check(str);
            if(res.size()==0)
                ans+=str;
            else
                ans+=res;
            ans+=" ";
            i=j;
        }
        
        ans.pop_back();
        
        return ans;
    }
};