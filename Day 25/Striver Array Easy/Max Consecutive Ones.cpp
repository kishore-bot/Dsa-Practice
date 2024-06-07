class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int oneS = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                oneS = 0;
            else
                oneS++;
            ans = max(ans , oneS);
        }
        return ans;
    }
};