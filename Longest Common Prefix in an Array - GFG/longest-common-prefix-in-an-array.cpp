// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
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
        return  links[ch-'a'];
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
    
    string check(string prefix,string ans)
    {
        node* newnode=root;
        int l=ans.length();
        string temp="";
        
        for(int i=0;i<l;i++)
        {
            if(!newnode->containsKey(prefix[i]))
            {
                  return temp;
            }
            if(prefix[i]!=ans[i])
                  return temp;
            temp+=ans[i];
            newnode=newnode->get(prefix[i]);
            
            
        }
        return temp;
    }
    
};

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        trie t;
        for(int i=0;i<N;i++)
        {
            t.insert(arr[i]);
        }
        
        string ans=arr[0];
        
        string ans2="";
        for(int i=0;i<N;i++)
        {
            string x=t.check(arr[i],ans);
            if(x.size()==0)
              return "-1";
            ans=x;
            
              
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends