/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
       
        if(head==NULL)
            return NULL;
        
        TreeNode* root=new TreeNode();
        int ct=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }

        
        if(ct&1)
        {
    
            int times=ct/2;

            ListNode* temp=head;
            while(times--)
            {
                temp=temp->next;
            }
            
            if(ct==1)
            {
                root->val=temp->val;
                root->left=NULL;
                root->right=NULL;
                return root;
            }
           
            
            ListNode* front=head;
            
            ListNode* back=temp->next;
            
            times=ct/2;
            
            while(times--)
            {
                if(times==0)
                    front->next=NULL;
                cout<<front->val<<" ";
                front=front->next;
            }
            front=head;
          
          
            
            back=temp->next;
 
            root->val=temp->val;
     
            root->left=NULL;
            root->right=NULL;

            root->left=sortedListToBST(front);
            root->right=sortedListToBST(back);
            
           
        }
        else
        {
            int times=ct/2;
            ListNode* temp=head;
            while(times--)
            {
                if(temp==NULL)
                    break;
                temp=temp->next;
            }
        
            
            if(ct==0)
            {
                if(temp!=NULL)
                root->val=temp->val;
                root->left=NULL;
                root->right=NULL;
                return root;
            }
           
            
            ListNode* front=head;
            
            ListNode* back=temp->next;
            
            
            times=ct/2;
            
            while(times--)
            {
                if(times==0)
                    front->next=NULL;
               front=front->next;
            }
            front=head;
         
            
            back=temp->next;
      
            
            root->val=temp->val;
            root->left=NULL;
            root->right=NULL;

            root->left=sortedListToBST(front);
            root->right=sortedListToBST(back);
            
        }
        
        
        
        
        
        return root;
        
        
        
        
        
        
        
    }
};