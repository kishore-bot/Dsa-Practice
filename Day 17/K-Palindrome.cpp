// https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1
// Easy

class Solution
{
public:
    vector<vector<int>> memo;
    int minDeletions(int l, int r, const string &str)
    {

        if (l >= r)
        {
            return 0;
        }
        if (memo[l][r] != -1)
        {
            return memo[l][r];
        }
        if (str[l] == str[r])
        {
            memo[l][r] = minDeletions(l + 1, r - 1, str);
        }
        else
        {
            memo[l][r] = 1 + min(minDeletions(l + 1, r, str), minDeletions(l, r - 1, str));
        }
        return memo[l][r];
    }
    int kPalindrome(string str, int n, int k)
    {
        memo.resize(n, vector<int>(n, -1));
        return minDeletions(0, n - 1, str) <= k;
    }
};