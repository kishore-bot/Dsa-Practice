// Extreme Brutee
class Solution
{
public:
    int lenOfLongSubarr(int A[], int n, int k)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int res = 0;
                for (int l = i; l <= j; l++)
                {
                    res += A[l];
                }
                if (res == k)
                {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// Brutte
class Solution {
public:
    int lenOfLongSubarr(int A[], int n, int k) 
    { 
        int ans = 0;
        
        // Iterate over all possible starting points of sub-arrays
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int j = i; j < n; j++) {
                res += A[j];
                if (res == k) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    } 
};


// Better for only poaitives // Optimal for both +ves and -ves
class Solution {
public:
    int lenOfLongSubarr(int A[], int n, int k) 
    { 
        int ans = 0;
        int sum = 0;
        std::unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            sum += A[i];

            if (sum == k) {
                ans = i + 1;
            }

            if (mpp.find(sum - k) != mpp.end()) {
                ans = std::max(ans, i - mpp[sum - k]);
            }

            if (mpp.find(sum) == mpp.end()) {  //I think this line for longest for shotest we not need if statement
                mpp[sum] = i;
            }
        }

        return ans;
    } 
};


// Optimal SOl For only Pos

class Solution {
public:
    int lenOfLongSubarr(int A[], int n, int k) 
    { 
        int ans = 0;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += A[right];

            // Shrink the window as long as the sum is greater than k
            while (left <= right && sum > k) {
                sum -= A[left];
                left++;
            }

            // Check if the current window's sum is equal to k
            if (sum == k) {
                ans = max(ans, right - left + 1);  // Use right - left + 1 for correct length
            }
        }

        return ans;
    } 
};