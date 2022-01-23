
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
    void insert(int n)
    {
        node* newnode=root;

        for(int i=31;i>=0;i--)
        {
            int bit;
            if(n&(1<<i))
                bit=1;
            else
                bit=0;
         //   cout<<bit<<" ";
            // if(bit==2)
            //     cout<<n<<endl;
            if(!newnode->containsKey(bit))
            {
                newnode->put(bit,new node());
            }

            //moves to reference trie
            newnode=newnode->get(bit);
        }

    }


    
    int check(int num)
    {
        node* newnode=root;
        
        int n=0;
        
        for(int i=31;i>=0;i--)
        {
            int bit;
            if(num&(1<<i))
                bit=1;
            else
                bit=0;
            if(newnode->containsKey(!bit))
            {
                n=n|(1<<i);
                newnode=newnode->get(!bit);
            }
            else
            {
                newnode=newnode->get(bit);
            }
        }
        
        return n;
    }
};


class Solution {
private:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[1]<b[1])
            return true;
        else
            return false;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(),nums.end());
        
        int qs=queries.size();
        int ns=nums.size();
        
        trie t;
        
        vector<vector<int>> q(qs);
        int ind=0;
        
        for(auto &it:queries)
        {
            q[ind].push_back(it[1]);
            q[ind].push_back(it[0]);
            q[ind].push_back(ind++);
        }
        
        // for(int i=0;i<qs;i++)
        // {
        //     cout<<q[i][0]<<" "<<q[i][1]<<" "<<q[i][2];
        //     cout<<endl;
        // }
        
        sort(q.begin(),q.end());
        
        // for(int i=0;i<qs;i++)
        // {
        //     cout<<q[i][0]<<" "<<q[i][1]<<" "<<q[i][2];
        //     cout<<endl;
        // }
        
        vector<int> ans(qs);
        
        int j=0;
        for(auto &it:q)
        {
            
            int flag=0;
            while(j<ns && nums[j]<=it[0])
            {
                t.insert(nums[j]);
                j++;
            }
           
            
            int x;
            if(j!=0)
            {
                ans[it[2]]=t.check(it[1]);
                //ans[q[i][2]]=x;
            }
            else
            {
                ans[it[2]]=-1;
            }
            //cout<<max<<endl;
        }
        
        
        return ans;
            
        
    }
};