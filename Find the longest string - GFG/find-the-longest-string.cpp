//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node
{
    struct Node* freq[26];
    int flag=0;
};

class Trie
{
    struct Node* root;
    
    public:
    Trie()
    {
        root=new Node();    
    }
    
    void insert(string str)
    {
        int l=str.length();
        Node* node=root;
        
        for(int i=0;i<l;i++)
        {
            if(!node->freq[str[i]-'a'])
            {
                node->freq[str[i]-'a']=new Node();
            }
            node=node->freq[str[i]-'a'];
        }
        
        node->flag=1;
    }
    
    bool solve(string word)
    {
       // return true;
        int l=word.length();
        Node* node=root;
        
        for(int i=0;i<l;i++)
        {
            
            if(node->freq[word[i]-'a'])
            {
                node=node->freq[word[i]-'a'];
            }
         //   cout<<node->flag<<endl;
            if(node->flag==0)
               return false;
        }
        
        return true;
    }
};


class Solution
{
public:
    string longestString(vector<string> &words)
    {
        int size=words.size();
      //  cout<<size<<endl;
        sort(words.begin(),words.end());
        Trie t;
        
        for(int i=0;i<size;i++)
        {
     //       cout<<words[i]<<endl;
            t.insert(words[i]);    
        }
        
        string res;
        set<string> st;
        int maxi=0;
        
        for(int i=0;i<size;i++)
        {
            bool ans=t.solve(words[i]);
            if(ans==true)
            {
                //maxi=max(maxi,words[i].length());
                if(maxi<words[i].length())
                   maxi=words[i].length();
                   
            }
        }
        
        for(int i=size-1;i>=0;i--)
        {
            if(words[i].length()==maxi)
            {
                //cout<<words[i]<<endl;
                bool ans=t.solve(words[i]);
                if(ans==true)
                {
                    res=words[i];
                }    
            }
            
        }
        
        return res;
    }
};



























//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends