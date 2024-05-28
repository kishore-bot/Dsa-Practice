// Medium
// ?
// https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

Bruteforce Approach
    Intuition
        The recursive approach explores all possible subsequences without memoization,
    considering whether each element should be taken or not based on the given condition(the absolute difference is 1).It recursively calculates the length of subsequences by branching at each element.

                                                            Implementation Recursive Solve Function(solve) : The function takes parameters ind(current index),
prev(index of the previous element), n(size of the array), and nums(input array).Base case: If the current index is beyond the array size, return 0.
Two variables, take and nottake, represent the lengths of subsequences with and without including the current element.
If the previous element is -1 or the absolute difference is 1, consider taking the current element and calling the solve function recursively for the next index.
Consider not taking the current element and calling the solve function recursively for the next index.
Return the maximum of taking or not taking the current element.
Main Function (longestSubsequence):
Convert the input array to a vector.
Call the recursive solve function with initial parameters.
Code

class Solution
{
public:
    int solve(int ind, int prev, int n, vector<int> nums)
    {
        // Base case: If the index is beyond the array size, return 0
        if (ind >= n)
        {
            return 0;
        }

        int take = 0, nottake = 0;

        // If the previous element is -1 or the absolute difference is 1, consider taking the current element
        if (prev == -1 || abs(nums[ind] - nums[prev]) == 1)
        {
            take = 1 + solve(ind + 1, ind, n, nums);
        }

        // Consider not taking the current element
        nottake = solve(ind + 1, prev, n, nums);

        // Return the maximum of taking or not taking the current element
        return max(take, nottake);
    }

    int longestSubsequence(int N, int A[])
    {
        // Convert the input array to a vector
        vector<int> nums(A, A + N);

        // Call the recursive solve function with initial parameters
        return solve(0, -1, N, nums);
    }
};
Complexity
    Time Complexity : The time complexity is exponential,
                      O(2 ^ n),
                      where n is the size of the input array.The algorithm explores all possible combinations through recursion without memoization.

                      Space Complexity : The space complexity is O(N) due to the recursive call stack. Each recursive call consumes space on the call stack, and the maximum depth of the stack is proportional to the size of the input array N

Brute-Optimized Approach
Intuition
This approach uses dynamic programming with memoization to find the length of the longest subsequence where the absolute difference between adjacent elements is one. It explores all possible subsequences, considering whether each element should be taken or not based on the given condition.

Implementation
Recursive Solve Function (solve):
The function takes parameters ind (current index), prev (index of the previous element), n (size of the array), nums (input array), and dp (DP table for memoization).
Base case: If the current index is beyond the array size, return 0.
Memoization: Check if the result for the current state is already computed and return it if available.
Take and Not Take:
Initialize take and nottake variables to represent the lengths of subsequences with and without including the current element.
If the previous element is -1 or the absolute difference is 1, consider taking the current element and call the solve function recursively for the next index.
Consider not taking the current element and call the solve function recursively for the next index.
Result and Memoization:
Store the result in the DP table for the current state (dp[ind][prev + 1]).
Return the maximum of the lengths obtained by taking or not taking the current element.
Main Function (longestSubsequence):
Convert the input array to a vector.
Initialize a DP table with -1.
Call the recursive solve function with initial parameters.
Code

class Solution
{
public:
    int solve(int ind, int prev, int n, int nums[], vector<vector<int>> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if (dp[ind][prev + 1] != -1)
        {
            return dp[ind][prev + 1];
        }

        int take = 0, nottake = 0;

        if (prev == -1 || abs(nums[ind] - nums[prev]) == 1)
        {
            take = 1 + solve(ind + 1, ind, n, nums, dp);
        }

        nottake = solve(ind + 1, prev, n, nums, dp);

        return dp[ind][prev + 1] = max(take, nottake);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(0, -1, N, A, dp);
    }
};
Complexity
Time Complexity: The time complexity is O(n^2), where n is the size of the input array. The recursion tree is pruned using memoization, and each subproblem is solved only once, hence time complexity becomes O(n^2),
Space Complexity: The space complexity is O(n^2), where n is the size of the input array. This is due to the memoization table (dp), which stores results for subproblems, leading to a square matrix proportional to the size of the input array.
Expected Approach
Intuition
The approach is to use dynamic programming to find the length of the longest subsequence where the absolute difference between adjacent elements is one. It iterates through the array in reverse order, comparing each element with subsequent elements. If the absolute difference is one, it updates the length of the longest subsequence ending at that position. The final result is the maximum length found during the iteration.

Example:
1.png1.png
Implementation:
Initialization:
Create a list lst initialized with 1 for each element in the array A.
Dynamic Programming Iteration:
Iterate backward through the array A (from the last element to the first).
For each element at index i, iterate through the elements to its right (from index i+1 to the end of the array).
Update Longest Subsequence Length:
If the absolute difference between A[i] and A[j] is 1, update lst[i] to be the maximum value between its current value and 1 + lst[j].
This step ensures that lst[i] represents the length of the longest subsequence ending at index i considering the given condition.
Return Maximum Length:
After the dynamic programming iteration, return the maximum value in the lst list, which represents the length of the overall longest subsequence.
Code

//Back-end complete function Template for C++

class Solution
{
public:
    int longestSubseq(int n, vector<int> a)
    {
        // Initializing the dp array
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1;

        // Calculating longest subsequence with adjacent elements having
        // difference of 1
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(a[i] - a[j]) == 1)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // calculating the answer
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);

        return ans;
    }
};
Complexity
    Time Complexity : The time complexity is
                      O(n ^ 2),
                      where n is the size of the input array.This is because the algorithm uses a nested loop to compare each pair of elements in the array,
                      resulting in quadratic time complexity.

                      Space Complexity : The space complexity is O(n),
                      where n is the size of the input array.The algorithm uses an additional list of size n to store the length of the longest subsequence ending at each index.

                      Useful links to help you understand the concepts of this problem