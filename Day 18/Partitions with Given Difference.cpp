// 
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1


Brute Force Approach:
Intuition:
The idea is to use the recursion and find all the possible partitions for the subset.

Implementation:


Copy-of-Copy-of-Copy-of-P-(6)-(2)


We first calculate the total sum of all elements in the array.
We check if the total sum is less than the given difference d or if (totalSum - d) is odd. In such cases, it's not possible to partition the array according to the given conditions, so we return 0.
Otherwise, we calculate the target sum by subtracting d from the total sum and dividing it by 2.
We call the solve function with the parameters n (size of the array), target, and the array arr and return it.
We define a recursive function solve that takes three parameters: the current index i, the remaining sum, and the array arrarr.
The base case is when i=0. If the remaining sum is 0, we return 1 (indicating a valid partition), otherwise, we return 0.
Otherwise, we recursively call the function for the (i−1)th index.
We update the answer by adding the counts of partitions where the current element is included if the remaining sum is greater than or equal to the current element.
Return the ans.
Code:

class Solution {
public:
    int mod = (int)1e9 + 7;

    int solve(int i, int sum, vector<int>& arr)
    {

        if (i == 0) {
            if (sum == 0) {
                return 1;
            }
            return 0;
        }

        int ans = solve(i - 1, sum, arr);

        if (sum >= arr[i - 1]) {
            ans = (ans
                   + solve(i - 1, sum - arr[i - 1], arr))
                  % mod;
        }

        return ans;
    }

    int countPartitions(int n, int d, vector<int>& arr)
    {
        // Code here
        int totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += arr[i];
        }

        if (totalSum < d || (totalSum - d) % 2) {
            return 0;
        }

        int target = (totalSum - d) / 2;

        return solve(n, target, arr);
    }
};
Complexity:
Time Complexity: O(2N), As we are using recursion to find all the possible partitions for the subset.
Space Complexity: O(N), As the size of the recursive call stack is N.
Expected Approach:
Intuition:
To count the number of partitions where the difference between the sums of the two subsets is equal to a given difference d, we can use dynamic programming. We'll iterate through the array and for each element, we'll compute the count of partitions that satisfy the conditions.

Implementation:


Copy-of-Copy-of-Copy-of-P-(6)-(2)


We calculate the total sum of all elements in the array.
We check if the difference between the total sum and d is negative or odd. In such cases, it's not possible to partition the array according to the given conditions, so we return 0.
Otherwise, we calculate the target sum as (totSum - d)/2, as we need to find partitions where the difference between the two subsets is d.
We call the findWays function with the target sum and the array.
We initialize a vector prev of size tar+1 to store the count of partitions for each possible sum up to the target.
We handle the base cases:
If the first element of the array is 0, there are two cases: either we pick or do not pick this element.
If the first element is not 0 and it is less than or equal to the target, there is one case: we pick this element.
Then, for each element in the array, starting from the second element:
We iterate through all possible target sums from 0 to tar.
For each target sum, we calculate the count of partitions:
If we do not take the current element, the count remains the same as the previous count for the same target sum.
If we take the current element, the count is equal to the count for the target sum minus the current element's value.
We update the cur vector with the counts for all target sums.
Return prev[tar].
Code:

class Solution {
  public:
    int mod = (int)1e9 + 7;

    int findWays(vector<int>& num, int tar) {
        int n = num.size();

        vector<int> prev(tar + 1, 0);

        if (num[0] == 0)
            prev[0] = 2; // 2 cases -pick and not pick
        else
            prev[0] = 1; // 1 case - not pick

        if (num[0] != 0 && num[0] <= tar) prev[num[0]] = 1; // 1 case -pick

        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(tar + 1, 0);
            for (int target = 0; target <= tar; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (num[ind] <= target) taken = prev[target - num[ind]];

                cur[target] = (notTaken + taken) % mod;
            }
            prev = cur;
        }
        return prev[tar];
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        // Checking for edge cases
        if (totSum - d < 0 || (totSum - d) % 2) return 0;

        return findWays(arr, (totSum - d) / 2);
    }
};
Complexity:
Time Complexity: O(N*MAX_SUM), As we are running a loop of size N*MAX_SUM, where N and MAX_SUM denote the number of elements in the array and the sum of array elements.
Space Complexity: O(MAX_SUM), As we have made prev and the cur vector of size MAX_SUM.
Alternate Approach:
Intuition:
To solve this problem, we can use dynamic programming. We'll define a recursive function that calculates the count of partitions satisfying the given conditions. We'll use memoization to optimize the recursive approach by avoiding redundant calculations.

Implementation:
We calculate the total sum of all elements in the array.
We check if the total sum minus d is negative or odd. In such cases, it's not possible to partition the array according to the given conditions, so we return 0.
Otherwise, we calculate the target sum as (totalSum - d)/2​, as we need to find partitions where the difference between the two subsets is d.
We initialize a 2D vector dp of size (n + 1) x (target + 1) with initial values set to -1 for memorization.
We call the solve function with the target sum, the array, and the memoization vector.
We handle the base case:
If i is 0 and sum is 0, we have found a valid partition, so we return 1.
If i is 0 but sum is not 0, we cannot achieve the target sum, so we return 0.
If the result for the current state (i, sum) is already calculated and stored in the dp array, we return it directly.
Otherwise, we recursively call the solve function for two cases:
Excluding the current element (arr[i-1]) and keeping the target sum unchanged.
Including the current element (arr[i-1]) and subtracting its value from the target sum.
We update the result for the current state (i, sum) in the dp array and return it.
Finally, we return the result obtained from the solve function.
Code:

class Solution {
  public:
    
     int mod = (int)1e9 + 7;
     
     int solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
         
            if (i == 0) {
                if (sum == 0) {
                    return 1;
                }
                return 0;
            }
        
            if (dp[i][sum] != -1) {
                return dp[i][sum];
            }
            
            dp[i][sum] = solve(i - 1, sum, arr, dp);
        

            if (sum >= arr[i - 1]) {
                dp[i][sum] = (dp[i][sum] + solve(i - 1, sum - arr[i - 1], arr, dp)) % mod;
            }
        
            return dp[i][sum];
         
     }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
            int totalSum = 0;
        
            for (int i = 0; i < n; ++i) {
                totalSum += arr[i];
            }
    
            if (totalSum < d || (totalSum - d) % 2) {
                return 0;
            }
        
            int target = (totalSum - d) / 2;
            
            vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        
            return solve(n, target, arr, dp);
    
    }
};
Complexity:
Time Complexity: O(N*MAX_SUM), As we have N*MAX_SUM different states in the solution, where N and MAX_SUM denote the number of elements in the array and the sum of array elements.
Space Complexity: O(N*MAX_SUM), As we have made a dp array of size size N*MAX_SUM, where N and MAX_SUM denote the number of elements in the array and the sum of array elements.
Useful links to help you understand the concepts of this problem:

https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/