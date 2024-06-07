// every element in the array appears once except for one element that appears twice


// Better 

// class Solution {
// public:
//     int findDuplicate(std::vector<int>& nums) {
//         std::unordered_set<int> seen;
//         for (int num : nums) {
//             if (seen.count(num)) {
//                 return num;  // Duplicate found
//             }
//             seen.insert(num);
//         }
//         return -1;  // This line will never be reached if the input guarantees one duplicate
//     }
// };



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Finding the intersection point of the two runners.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Finding the entrance to the cycle.
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;  // or return fast, both are the same at this point
    }
};

int main() {
    vector<int> nums = {1, 5, 4,2, 3, 2};
    Solution sol;
    int cx =  sol.findDuplicate(nums);
    cout<<cx;
    return 0;
}

// Note only find the answer if the array elem x = 1 < x < nums.size()
