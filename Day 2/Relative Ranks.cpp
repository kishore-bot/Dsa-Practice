// TRYCKY EASY
// https://leetcode.com/problems/relative-ranks/description/


// Optimal 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        vector<string> rankNames = {"Gold Medal", "Silver Medal",
                                    "Bronze Medal"};
        vector<int> copyScore = score;
        sort(copyScore.begin(), copyScore.end(),greater<int>());
        unordered_map<int, int> rank;
        int rankCt = 1;
        for (auto sc : copyScore)
            rank[sc] = rankCt++;
        for (int i = 0; i < score.size(); i++) {
            int actualRank = rank[score[i]];
            ans[i] = (actualRank <= 3) ? rankNames[actualRank - 1]
                                       : to_string(actualRank);
        }
        return ans;
    }
};

// https://www.youtube.com/watch?v=EcPtgVdK2R8