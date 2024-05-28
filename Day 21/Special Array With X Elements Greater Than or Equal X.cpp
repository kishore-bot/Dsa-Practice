// Easy

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= cnt)
            {
                cnt++;
                if (cnt > nums[i])
                    return -1;
            }
            else
                return cnt;
        }
        return n;
    }
};