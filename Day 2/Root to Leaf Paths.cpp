// Medium
// Tree

// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
private:
    void helper(Node* root, vector<int>& res, vector<vector<int>>& ans) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(res);
        }
        helper(root->left, res, ans);
        helper(root->right, res, ans);
        res.pop_back();
    }
public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(root, res, ans);
        return ans;
    }
};