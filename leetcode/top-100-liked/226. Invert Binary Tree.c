/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void invert(struct TreeNode* root)
{
  if (root == NULL)
    return;
  struct TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  invert(root->left);
  invert(root->right);  
}

struct TreeNode* invertTree(struct TreeNode* root)
{
  invert(root);
  return root;
}
