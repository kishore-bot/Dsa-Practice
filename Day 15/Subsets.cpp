// Medium
// Using Bit Manpulation
// https://leetcode.com/problems/subsets/submissions/1266391747/?envType=daily-question&envId=2024-05-21


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> res;
            for (int j = 0; j < n; j++) {
                if (  i & (1 << j))
                    res.push_back(nums[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};