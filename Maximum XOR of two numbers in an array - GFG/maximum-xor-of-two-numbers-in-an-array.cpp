// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

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


    
    int check(string word)
    {
        node* newnode=root;
        int l=word.length();
        
        int x;
        int n=0;
        for(int i=0;i<l;i++)
        {
            x=word[i]-'0';
            if(x==0)
            {
                if(!newnode->containsKey(1))
                {
                    n=n|(0<<(31-i));
                     newnode=newnode->get(0);
                }
                else
                {
                   n=n|(1<<(31-i));
                     newnode=newnode->get(1);
                }
            }
            else
            {
                if(!newnode->containsKey(0))
                {
                     n=n|(0<<(31-i));
                     newnode=newnode->get(1);
                }
                else
                {
                    n=n|(1<<(31-i));
                     newnode=newnode->get(0);
                }
            }
           
        }
        
        return n;
    }
};


class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        vector<int> nums;
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(arr[i]);
        }
        
        trie t;
        
        vector<string> str;
        
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=31;j>=0;j--)
            {
                int x=((nums[i]>>j)&1);
                s+=x+'0';
            }
            str.push_back(s);
            t.insert(s);
        }
        
        int max=0;
        
        for(int i=0;i<n;i++)
        {
            int x=t.check(str[i]);
            if(x>max)
                max=x;
        }
        
        return max;
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends