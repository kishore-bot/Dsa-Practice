// Brutee
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) {
            bool find = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i == nums[j]){
                    find = 1;
                    break;
                }
            }
            if (find == 0)
                return i;
        }
        return nums.size() + 1;
    }
};

// Better
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);  
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }
        for (int i = 0; i <= n; i++) {  
            if (hash[i] == 0)
                return i;   
        }
        return n + 1; 
    }
};

// Optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumOfNaturalNo = n * (n + 1) / 2;
        int sumOfArrElm = 0;
        for (int i = 0; i < n; i++) {
            sumOfArrElm += nums[i];
        }
        return sumOfNaturalNo - sumOfArrElm;
    }
};
// Or using accumulate fun
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        return (n * (n + 1)/2) - sum;
    }
};

// Super Optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorResult = n;  // Initialize xorResult with n
        for (int i = 0; i < n; i++) {
            xorResult ^= nums[i];
            xorResult ^= i;
        }
        return xorResult;
    }
};