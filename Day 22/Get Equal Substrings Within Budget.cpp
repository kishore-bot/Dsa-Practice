// Medium
// 2 pOinrt

// https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int i = 0, j = 0, ans = 0, curCost = 0;
        while (j < n)
        {
            curCost += abs(t[j] - s[j]);
            while (i < n and curCost > maxCost)
            {
                curCost -= abs(t[i] - s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};