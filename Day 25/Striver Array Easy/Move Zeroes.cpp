// Brutte
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) temp.push_back(nums[i]);
        }
        
        int i = 0;
        for(; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
        
        for(; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// Optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = 0; // Position to place the next non-zero element
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
            }
        }
    }
};
