// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) {
            if(sum == root->val) return true;
            return false;
        }
        bool hasLeft = false, hasRight = false;
        if(root->left) hasLeft = hasPathSum(root->left, sum-root->val);
        if(root->right) hasRight = hasPathSum(root->right, sum-root->val);
        return hasLeft || hasRight;
    }
};
