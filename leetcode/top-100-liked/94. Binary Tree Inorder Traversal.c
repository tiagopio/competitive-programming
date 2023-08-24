/* 
Given the root of a binary tree, return the inorder traversal of its nodes' values.

- Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]
- Example 2:

Input: root = []
Output: []
- Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int i = 0;
int arr[101] = {0};

void inorder(struct TreeNode* root)
{
  if (root != NULL)
  {
    inorder(root->left);
    arr[i++] = root->val;
    inorder(root->right);
  }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  inorder(root);
  int *ans = malloc(i * sizeof(int));
  for (int j = 0; j < i; j++) ans[j] = arr[j];
  *(returnSize) = i;
  i = 0;
  return ans;
}
