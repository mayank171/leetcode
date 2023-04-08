/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*,Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
             return NULL;
        
        
        queue<Node*> q;
        q.push(node);
        
        
        while(!q.empty())
        {
            Node* node=q.front();
      //      cout<<node->val<<endl;
            q.pop();
            
            if(mp.find(node)==mp.end())
            {
                mp[node]=new Node(node->val,{});
            }
            
            for(int i=0;i<node->neighbors.size();i++)
            {
                if(mp.find(node->neighbors[i])==mp.end())
                   q.push(node->neighbors[i]);    
            }
        }
        
        q.push(node);
        set<Node*> st;
        Node* cur=mp[node];
        
        int maxi=0;
        
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            
            maxi=max(maxi,node->val);
            
            if(st.find(mp[node])==st.end())
                st.insert(mp[node]);
            else
                continue;
            
            for(int i=0;i<node->neighbors.size();i++)
            {
                Node* adjnode=node->neighbors[i];
                if(st.find(mp[adjnode])==st.end())
                {
                    mp[node]->neighbors.push_back(mp[adjnode]);
                    mp[adjnode]->neighbors.push_back(mp[node]);
                    
                    q.push(adjnode);
                    
                }
            }
        }
        
        return cur;
        
//         for(auto &it:st)
//         {
//             Node* node=it;
            
//         }
        
    }
};























