// Brutte

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s;
        for (auto i : nums)
        {
            s.insert(i);
        }
        int k = 0;
        for (auto i : s)
        {
            nums[k] = i;
            k++;
        }
        return s.size();
    }
};

// Optimal
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        for (auto i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[k])
            {
                k += 1;
                nums[k] = nums[i];
            }
        }
        return k + 1;
    }
};