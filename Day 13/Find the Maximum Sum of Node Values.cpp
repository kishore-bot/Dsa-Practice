// Hard
// Bit Manipulation | Tree | Graphs
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/




class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, sacrify = INT_MAX;
        for (auto el : nums) {
            long long x = el^k; 
            if (x > el) {
                sum += x;
                sacrify = min(sacrify, (long long)x - el);
                cnt++;
            } else {
                sum += el;
                sacrify = min(sacrify, (long long)el - x);
            }
        }
        if (cnt % 2 == 0)
            return sum;
        return sum - sacrify;
    }
};

// https://www.youtube.com/watch?v=3t7y4mBJDoM