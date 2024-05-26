// Hard
// DP 
// https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25


class Solution {
private:
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& dp) {
        if (s.empty())
            return {""};
        if (dp.find(s) != dp.end())
            return dp[s];

        vector<string> subStr, wholeStr;
        for (string w : wordDict) {
            string iGot = s.substr(0, w.size());
            if (iGot != w)
                continue;
            subStr = helper(s.substr(w.size()), wordDict, dp);
            for (string ans : subStr) {
                string space = ans.empty() ? "" : " ";
                wholeStr.push_back(w + space + ans);
            }
        }
        return dp[s] = wholeStr;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> dp;
        vector<string> ans = helper(s, wordDict, dp);
        return ans; 
    }
};
// https://www.youtube.com/watch?v=SFZz19dqLcI

Dry Run
Let's do a dry run with an example:

s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Initial Call:

Call wordBreak("catsanddog", wordDict).
First Call to helper:

helper("catsanddog", wordDict, dp)
Loop Through wordDict:

Check cat: iGot = "cat" matches, call helper("sanddog", wordDict, dp).
Recursion:
Call helper("sanddog", wordDict, dp)
Loop through wordDict
Check cat: iGot = "san" doesn't match, continue.
Check cats: iGot = "sand" matches, call helper("dog", wordDict, dp).
Recursion:
Call helper("dog", wordDict, dp)
Loop through wordDict
Check cat, cats, and, sand: none match.
Check dog: iGot = "dog" matches, call helper("", wordDict, dp)
Base Case:
Return [""] as the string is empty.
Combine results: ["dog"].
Memoize: dp["dog"] = ["dog"].
Combine results: ["sand dog"].
Memoize: dp["sanddog"] = ["sand dog"].
Combine results: ["cats and dog", "cat sand dog"].
Memoize: dp["catsanddog"] = ["cats and dog", "cat sand dog"].
Second Call to helper:

Call helper("catsanddog", wordDict, dp) again
Use memoized results: dp["catsanddog"] = ["cats and dog", "cat sand dog"].
Result:

wordBreak("catsanddog", wordDict) returns ["cats and dog", "cat sand dog"].
Dry Run Breakdown
First level:

Try "cat" -> "sanddog"
Try "cats" -> "anddog"
Second level:

For "sanddog":
Try "sand" -> "dog"
(valid path found: "sand dog")
For "anddog":
Try "and" -> "dog"
(valid path found: "and dog")
Combine:

"cat" + "sand dog" -> "cat sand dog"
"cats" + "and dog" -> "cats and dog"
Thus, the final result is ["cats and dog", "cat sand dog"].

The corrected code should work as expected and the dry run confirms the logical flow and correctness.