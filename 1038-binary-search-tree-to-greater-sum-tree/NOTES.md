Use reverse inorder traversal.
Inorder is -> left root right
reverse inorder is -> right root left
​
We want sum of values greater than current node value so we must start from rightmost node as it has the max value.
​
Keep a variable to keep check of previously obtained maximum sum.
​
root->right until not null
assign variable=root->val=variable+root->val;
root->left until not null