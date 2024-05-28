// M
// DP (KNAPSACK 0-1 SAME CONCEPT)
// https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

// (KNAPSACK 0-1 SAME CONCEPT)

class Solution {
private:
    int helper(int n, int w, vector<int> &cost, vector<vector<int>> &dp) {
        if (w == 0) return 0;
        if (n == -1) return 1e9;
        
        if (dp[n][w] != -1) return dp[n][w];

        if ((n + 1) > w || cost[n] == -1) 
            return dp[n][w] = helper(n - 1, w, cost, dp);
        
        int y = helper(n - 1, w, cost, dp);
        int x = cost[n] + helper(n, w - (n + 1), cost, dp);
        
        return dp[n][w] = min(x, y);
    }

public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));  // Corrected dimensions
        int ans = helper(n - 1, w, cost, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};