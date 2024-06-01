// Easy
// String
//https://leetcode.com/problems/score-of-a-string/description/

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0 ;
        for(int i = 1 ;i < s .size();i++){
            int res = abs(s[i-1]-s[i]);
            score+=res;
        }
        return score;
    }
};