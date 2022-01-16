
struct node
{
    node* links[2];
    bool flag=false;

    bool containsKey(int x)
    {
        return (links[x]!=NULL);
    }

    void put(int x,node* newnode)
    {
        links[x]=newnode;
    }

    node* get(int x)
    {
        return links[x];
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

        int x;
        for(int i=0;i<word.length();i++)
        {
            x=word[i]-'0';
            if(!newnode->containsKey(x))
            {
                
                newnode->put(x,new node());
            }

            //moves to reference trie
            newnode=newnode->get(x);
        }

        newnode->setEnd();
    }


    
    string check(string word)
    {
        node* newnode=root;
        int l=word.length();
        
        int x;
        int num=0;
        string s="";
        for(int i=0;i<l;i++)
        {
            x=word[i]-'0';
            if(x==0)
            {
                if(!newnode->containsKey(1))
                {
                    //num+=num&(1<<(31-i));
                     s+='0';
                     newnode=newnode->get(0);
                }
                else
                {
                   // num+=num|(1<<(31-i));
                       s+='1';
                     newnode=newnode->get(1);
                }
            }
            else
            {
                if(!newnode->containsKey(0))
                {
                     //num+=num&(1<<(31-i));
                     s+='0';
                     newnode=newnode->get(1);
                }
                else
                {
                    //num+=num|(1<<(31-i));
                      s+='1';
                     newnode=newnode->get(0);
                }
            }
           
        }
        
        return s;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int n=nums.size();
        
        trie t;
        
        vector<string> str;
        
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=31;j>=0;j--)
            {
                int x=((nums[i]>>j)&1);
               // cout<<x<<endl;
                s+=x+'0';
            }
           // cout<<s<<endl;
            str.push_back(s);
            t.insert(s);
        }
        
        int max=0;
        
        for(int i=0;i<n;i++)
        {
           // cout<<"--"<<str[i]<<endl;
            string te=t.check(str[i]);
            
            //cout<<"----"<<te<<endl;
            int l=te.length();
            int p=0;
            for(int j=0;j<l;j++)
            {
                int x=te[j]-'0';
                p=p+x*pow(2,l-j-1);
            }
            
            if(p>max)
                max=p;
        }
        
        return max;
    }
};