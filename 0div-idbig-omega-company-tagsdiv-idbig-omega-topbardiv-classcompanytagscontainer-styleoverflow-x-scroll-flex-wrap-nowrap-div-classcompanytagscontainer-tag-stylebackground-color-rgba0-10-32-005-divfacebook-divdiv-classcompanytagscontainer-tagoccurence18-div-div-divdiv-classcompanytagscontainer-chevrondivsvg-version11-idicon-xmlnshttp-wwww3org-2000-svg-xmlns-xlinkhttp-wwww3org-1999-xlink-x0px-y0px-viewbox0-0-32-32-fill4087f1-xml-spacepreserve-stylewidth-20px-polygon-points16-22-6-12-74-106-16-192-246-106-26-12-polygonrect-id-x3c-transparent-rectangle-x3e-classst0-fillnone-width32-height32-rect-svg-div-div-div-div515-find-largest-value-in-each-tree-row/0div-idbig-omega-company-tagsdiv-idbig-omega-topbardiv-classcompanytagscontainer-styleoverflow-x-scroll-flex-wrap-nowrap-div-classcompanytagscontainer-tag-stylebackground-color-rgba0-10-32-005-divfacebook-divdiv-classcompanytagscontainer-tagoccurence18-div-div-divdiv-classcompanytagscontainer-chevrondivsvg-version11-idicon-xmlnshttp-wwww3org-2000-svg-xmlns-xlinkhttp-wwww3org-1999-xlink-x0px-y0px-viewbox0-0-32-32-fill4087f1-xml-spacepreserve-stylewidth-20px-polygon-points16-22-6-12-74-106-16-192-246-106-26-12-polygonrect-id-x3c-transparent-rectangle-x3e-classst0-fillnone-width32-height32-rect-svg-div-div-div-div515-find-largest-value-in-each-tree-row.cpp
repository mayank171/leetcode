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
    vector<int> ans;
  void preorder(TreeNode* root, int height) {
    if (!root) return;
    if (ans.size() < height) ans.push_back(root->val);
    else ans[height - 1] = max(ans[height - 1], root->val);
    preorder(root->left, height + 1);
    preorder(root->right, height + 1);
  }
public:
  vector<int> largestValues(TreeNode* root) {
    preorder(root, 1);
    return ans;
  }
};