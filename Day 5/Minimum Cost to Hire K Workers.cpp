// HARD PQ
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/submissions/1255057307/?envType=daily-question&envId=2024-05-11

// https://www.youtube.com/watch?v=KytaqLXEeJA&t=1557s


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        for (int i = 0; i < n; i++) {
            workers.push_back({(wage[i] * 1.0) / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        double ans = DBL_MAX, qualitySum = 0;
        priority_queue<int> q;
        for (auto w : workers) {
            double ratio = w.first;
            qualitySum += w.second;
            q.push(w.second);
            if (q.size() > k)
                qualitySum -= q.top(), q.pop();
            if (q.size() == k)
                ans = min(ans, qualitySum * ratio);
        }
        return ans;
    }
};
