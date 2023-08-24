/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
  if (root == NULL)
    return 0;
  else {
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    if (l > r)
      return l + 1;
    else
      return r + 1;
  }
}
