// Medium
// Grid Rec
// https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14

class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0  )
            return 0;
        int currVal = grid[i][j];
        int maxSum = 0;
        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};
        for (int d = 0; d < 4; d++) {
            int nI = i + dr[d];
            int nJ = j + dc[d];
            grid[i][j] = 0;
            maxSum = max(maxSum, currVal + dfs(nI, nJ, grid));
            grid[i][j] = currVal;
        }
        return maxSum;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
// https://www.youtube.com/watch?v=bst1LaMdHrw