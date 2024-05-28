// M
// DP LCS
// https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

class Solution {
public:
    int findMinCost(string s1, string s2, int a, int b) 
    {
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (m-dp[m][n])*a+(n-dp[m][n])*b;
    }
};