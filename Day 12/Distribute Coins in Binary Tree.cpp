// Dfs and Tree
// M
// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

class Solution {
public:
    int steps;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftRequired = dfs(root->left);
        int rightRequired = dfs(root->right);
        steps += abs(leftRequired) + abs(rightRequired);
        return (root->val - 1) + leftRequired + rightRequired;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }
};
// https://www.youtube.com/watch?v=RkVF5PdZJ1w