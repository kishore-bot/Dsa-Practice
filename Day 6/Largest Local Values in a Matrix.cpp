// Easy
// Mtrix
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

// Imp to solve question is to understant question
class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j) {
        int res = INT_MIN;
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                res = max(res, grid[k][l]);
            }
        }
        return res;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                ans[i][j] = helper(grid, i, j);
            }
        }
        return ans;
    }
};