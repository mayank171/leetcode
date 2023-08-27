//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

struct Node
{
    struct Node* freq[26];
    int ct;
};

class trie
{
    private:
    struct Node* root;
    
    public:
    int maxi;
    
    trie()
    {
        root=new Node();
        maxi=0;
    }
    
    void insert(string word)
    {
        int l=word.length();
        Node* node=root;
        for(int i=0;i<l;i++)
        {
            if(!node->freq[word[i]-'a'])
            {
                node->freq[word[i]-'a']=new Node();
            }
            node=node->freq[word[i]-'a'];
        }
        
        node->ct++;
        maxi=max(maxi,node->ct);
    }
    
    int search(string word)
    {
        int l=word.length();
        Node* node=root;
        for(int i=0;i<l;i++)
        {
            node=node->freq[word[i]-'a'];
        }
        
        return node->ct;
    }
};

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        trie t;
        map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            t.insert(arr[i]);
            if(mp.find(arr[i])==mp.end())
               mp[arr[i]]=i;
        }
        
        set<string> st;
        for(int i=0;i<n;i++)
        {
            int x=t.search(arr[i]);
         //   cout<<arr[i]<<" "<<x<<endl;
            if(x==t.maxi)
               st.insert(arr[i]);
        }
        
        if(st.size()>1)
        {
            string ans="";
            int maxi=-1;
            for(auto &it:st)
            {
                int ind=mp[it];
                if(ind>maxi)
                {
                    maxi=ind;
                    ans=it;
                }
            }
            
            return ans;
        }
        
        return *st.begin();
    }
};




















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends