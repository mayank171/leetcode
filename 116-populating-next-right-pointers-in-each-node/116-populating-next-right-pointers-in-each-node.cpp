/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void check(Node* root)
    {
        if(root==NULL)
            return ;
        
        if(root->left)
           {
               if(root->right!=NULL)
               {
                   root->left->next=root->right;
               }
               else
               {
                   root->left->next=NULL;
               }
           }
        if(root->right)
           {
               if(root->next!=NULL && root->next->left!=NULL)
               {
                   root->right->next=root->next->left;
               }
               else
               {
                   root->right->next=NULL;
               }
           }
        
        check(root->left);
        check(root->right);
            
    }
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        
        root->next=NULL;
        check(root);
        
        return root;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         queue<Node*> q;
        
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int size=q.size();
            
//             for(int i=0;i<size;i++)
//             {
//                 Node* node=q.front();
//                 q.pop();
//                 if(i+1==size)
//                 {
//                     node->next=NULL;
//                 }
//                 else
//                 {
//                     node->next=q.front();
//                 }
                
//                 if(node->left)
//                     q.push(node->left);
//                 if(node->right)
//                     q.push(node->right);
                
//             }
//         }
        
//         return root;
        
    }
};