// Medium
// Arr
// https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

// Brutte

class Solution {
  public:   
    int maxOccured(int n, int l[], int r[], int maxx) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int low = l[i];
            int high = r[i];
            while (low <= high && low <= maxx) {
                mpp[low]++;
                low++;
            }
        }

        int ans = INT_MAX; // Initialize to maximum possible integer value
        int f = 0; // Initialize frequency counter

        for (auto i : mpp) {
            if (i.second > f || (i.second == f && i.first < ans)) {
                ans = i.first;
                f = i.second;
            }
        }

        return ans;
    }
};

// OPtimal
// https://youtube.com/watch?v=lt_vDS2o0Xg
class Solution {
  public:   
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> freq(maxx + 1, 0);

        // Increment at l[i] and decrement at r[i] + 1
        for (int i = 0; i < n; i++) {
            freq[l[i]]++;
            if (r[i] + 1 <= maxx) {
                freq[r[i] + 1]--;
            }
        }

        // Compute prefix sums
        for (int i = 1; i <= maxx; i++) {
            freq[i] += freq[i - 1];
        }

        // Find the index with the maximum frequency
        int ans = 0;
        int f = 0;
        for (int i = 0; i <= maxx; i++) {
            if (freq[i] > f) {
                ans = i;
                f = freq[i];
            }
        }

        return ans;
    }
};