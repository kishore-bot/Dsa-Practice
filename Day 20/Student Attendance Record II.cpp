// HARD
// REC,DP
// https://leetcode.com/problems/student-attendance-record-ii/?envType=daily-question&envId=2024-05-26

#define MOD 1000000007

class Solution
{
private:
    int helper(int n, int absentCount, int consecutiveLateCount, vector<vector<vector<int>>> &memo)
    {
        if (n == 0)
            return 1;
        if (memo[n][absentCount][consecutiveLateCount] != -1)
            return memo[n][absentCount][consecutiveLateCount];

        int ans = 0;

        // Present Day
        ans = helper(n - 1, absentCount, 0, memo) % MOD;

        // Absent Day
        if (absentCount < 1)
            ans = (ans + helper(n - 1, absentCount + 1, 0, memo)) % MOD;

        // Late Day
        if (consecutiveLateCount < 2)
            ans = (ans + helper(n - 1, absentCount, consecutiveLateCount + 1, memo)) % MOD;

        return memo[n][absentCount][consecutiveLateCount] = ans;
    }

public:
    int checkRecord(int n)
    {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(n, 0, 0, memo);
    }
};

// https://www.youtube.com/watch?v=kx5t-A2kTDk