//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

struct node
{
    struct node* arr[26];
    int flag;
};


class trie
{
    public:
    struct node* root;
    
    trie()
    {
        root=new node();
    }
    
    void insert(string s)
    {
        int l=s.length();
        struct node* n=root;
        
        for(int i=0;i<l;i++)
        {
            if(!n->arr[s[i]-'a'])
            {
                n->arr[s[i]-'a']=new node();
            }
            n=n->arr[s[i]-'a'];
            n->flag++;
        }
        
       // n->flag++;
    }
    
    int check(string str,int l)
    {
        struct node* n=root;
        for(int i=0;i<l;i++)
        {
            if(!n->arr[str[i]-'a'])
               return 0;
            n=n->arr[str[i]-'a'];
        }
        
        return n->flag;
    }
};


class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        
        trie t;
        for(int i=0;i<n;i++)
        {
            t.insert(arr[i]);
        }
        
        int p;
        if(str.length()<k)
           p=str.length();
        else
           p=k;
        
        
        string kstr=str.substr(0,p);
        
        int ans=t.check(kstr,k);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends