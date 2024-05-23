// Medium
// https://leetcode.com/problems/k-th-smallest-prime-fraction/submissions/1254498135/

// https://www.youtube.com/watch?v=SmxdebjWvfs

// Better
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double val = (arr[i] * 1.0) / arr[j];
                pq.push({val, {i, j}});
                if (pq.size() > k)
                    pq.pop();
            }
        }
        pair<int, int> id = pq.top().second;
        return {arr[id.first], arr[id.second]};
    }
};

// Optimal uaing min heap
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        int n = arr.size();
        for (int i = 0; i < min(n - 1, k); i++)
        {
            pq.push({arr[i] * 1.0 / arr.back(), {i, n - 1}});
        }
        for (int times = 1; times <= k - 1; times++)
        {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first, j = top.second.second;
            if (j - 1 > i)
                pq.push({(arr[i] * 1.0) / arr[j - 1], {i, j - 1}});
        }
        pair<int, int> id = pq.top().second;
        return {arr[id.first], arr[id.second]};
    }
};
