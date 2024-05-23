// Easy
// Sort and Sliding window
// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

// Idea : sliding window explore all possibility i terms o0f 2 pointer
class Solution {
public:
    int findPair(int n, int x, std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());
        
        int left = 0;
        int right = 1;
        
        while (left < n && right < n) {
            int diff = arr[right] - arr[left];
            
            if (left != right && diff == x) {
                return 1;
            } else if (diff < x) {
                right++;
            } else {
                left++;
            }
        }
        
        return -1;
    }
};