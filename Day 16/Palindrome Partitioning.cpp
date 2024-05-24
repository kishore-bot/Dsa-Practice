// RECURSION STRING
// MEDIUM
// https://leetcode.com/problems/palindrome-partitioning/description/?envType=daily-question&envId=2024-05-22

class Solution
{
private:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

private:
    void dfs(int idx, string &s, vector<string> &res,
             vector<vector<string>> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(res);
            return;
        }
        for (int end = idx; end < s.size(); end++)
        {
            if (isPalindrome(s, idx, end))
            { // Fixing 'ind' to 'idx'
                res.push_back(s.substr(idx, end - idx + 1));
                dfs(end + 1, s, res, ans);
                res.pop_back(); // Fixing 'res.pop_back' to 'res.pop_back()'
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        if (s.empty())
            return ans;
        vector<string> res;
        dfs(0, s, res, ans);
        return ans;
    }
};

// https://www.youtube.com/watch?v=lk1xlGddaAM