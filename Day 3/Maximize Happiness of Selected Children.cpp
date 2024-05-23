// Medium
// Sorting
// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/


class Solution
{
public:
    long long maximumHappinessSum(std::vector<int> &happiness, int k)
    {
        long long ans = 0;
        int n = happiness.size();
        std::sort(happiness.begin(), happiness.end());
        for (int i = 0; i < k; i++)
        {
            if (i == 0)
            {
                ans += happiness[n - 1];
            }
            else
            {
                int x = happiness[n - 1 - i] - i;
                if (x > 0)
                {
                    ans = ans + x;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
