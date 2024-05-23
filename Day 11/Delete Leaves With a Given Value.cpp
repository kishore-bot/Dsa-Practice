// Medium
// Binary Tree and dfs
// https://leetcode.com/problems/delete-leaves-with-a-given-value/


/*
idea:
    * delete Node while Returning of fun
    * return NuLL if constarts satisfy 
    *   * if (root->left == NULL and root->right == NULL and root->val == target)
    *   * it means if the delettion of leaf node cause the parent node to become leaf it will also delete
    * for other Node return root
*/
class Solution {

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (root == NULL)
            return NULL;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == NULL and root->right == NULL and root->val == target)
            return NULL;
        return root;
    }
};

// https://www.youtube.com/watch?v=Ir7MIOREBsc&t=20s