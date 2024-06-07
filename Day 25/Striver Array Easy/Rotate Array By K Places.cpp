

// Optimal
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // To handle cases where k > n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Better / brutte
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (k == 0)
            return;

        vector<int> ans(nums.end() - k, nums.end()); // Copy the last k elements
        for (int i = n - 1; i >= k; i--)
        {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = ans[i];
        }
    }
};

// Another optimal From Babber Using % opterator
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (k == 0)
            return;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};