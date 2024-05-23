// Medium
// Not got
// https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1


// ANS FROM COMMENT (NOT UNDERSTOOD YET)
class Solution
{
public:
    int minSteps(int d)
    {
        int add = 1;
        int elem = 0, cnt = 0;
        while (elem < d)
        {
            elem += add;
            add++;
            cnt++;
        }
        while ((elem - d) % 2 != 0)
        {
            cnt++;
            elem += add;
            add++;
        }
        return cnt;
        // code here
    }
};

/* Editorial
Brute Force Approach:
Intuition:
The algorithm uses a recursive approach to explore different paths and find the minimum number of steps to reach the target destination.

Implementation:
Call the solve function and return the value returned by it,
Let's see what the solve function does,
If the current position is equal to the destination, the function returns the current step count, as the player has reached the target.
If the absolute value of the current position is greater than the value of the destination, the function returns a high value (INT_MAX), indicating that the current path is invalid.
For each recursive call, the function explores the two possible paths (left and right) from the current position, incrementing the step count and adjusting the current position accordingly.
The function continues recursively exploring the possible paths until it finds a path that reaches the destination or explores all possible paths without finding a valid solution.
Return the minimum among both of them.
Code:

class Solution {
public:
    int solve(int source, int step, int dest)
    {
        // base cases
        if (abs(source) > (dest))
            return INT_MAX;
        if (source == dest)
            return step;

        // at each point we can go either way

        // if we go on positive side
        int pos = solve(source + step + 1, step + 1, dest);

        // if we go on negative side
        int neg = solve(source - step - 1, step + 1, dest);

        // minimum of both cases
        return min(pos, neg);
    }

    int minSteps(int D)
    {
        // code here
        return solve(0, 0, D);
    }
};
Complexity:
Time Complexity: O(2d), As we explore all the possible paths using recursion.
Space Complexity: O(d), As the size of the recursive call stack is D.

Expected Approach:
Intuition:
We use the loop calculates the sum of the steps taken and continues until the sum is at least the target (abs(D)) and the difference between the sum and the target is even. This ensures that the player can adjust their steps to reach the exact destination, and the function returns the final number of steps

Implementation:
Example: d = 10
Initialization: target = abs(d) = 10, step = 0, sum = 0
Step 1: step = step + 1 = 1, sum = sum+step = 1
Step 2: step = step + 1 = 2, sum = sum+step = 3
Step 3: step = step + 1 = 3, sum = sum+step = 6
Step 4: step = step + 1 = 4, sum = sum+step = 10, As the sum is equal to target and (sum-target) = (10-10) = 0, is even so we break out of the loop,
we get the final answer as step = 4.

Initialize the target as the absolute value of D and sum and step as zero.
Run a loop until the sum is less than the target or the difference between the sum and target is not even
In each iteration, the step counter (step) is incremented by one, and the sum (sum) is increased by the value of the current step.
Return the step.
Code:

//Back-end complete function Template for C++

class Solution {
  public:
    // Function to find the minimum number of steps required
    int minSteps(int d) {
        int target = abs(d), sum = 0, step = 0;

        // Execute the loop until the sum is less than the target or the difference
        // between the sum and target is not even
        while (sum < target || (sum - target) % 2 != 0) {
            // Increment the step count and add it to the sum
            step++;
            sum += step;
        }
        // Return the final step count
        return step;
    }
};
Complexity:
Time Complexity: O(d), As the loop runs for d times in worst case.
Space Complexity: O(1), As we are using constant extra space.
Optimized Approach-1:
Intuition:
We use binary search to find the minimum number of steps required to accumulate a sum that is at least the target value. This is efficient since the sum of the first mid numbers ((long)mid*(mid+1)/2) can be found quickly. Since the ith move must take i steps, the parity (even or odd) of the current number of steps and the target sum will determine the final answer. The function checks the parity of the current sum and the target value. After the binary search finds a potential minimum number of steps (lo), the function adjusts the result if the parity doesn't match. It ensures the sum can be adjusted to reach the target by either adding one or two steps.

Implementation:
Initialize the search range with low as 1 and high as a large enough number (e.g., 50000).
Run a loop while low is less than high,
Initialize a variable mid equal to (low + (high - low)/2).
Calculate the sum of the first mid natural numbers using the formula (mid * (mid + 1)) / 2.
If the sum is equal to or greater than the target, the search range is adjusted to narrow the search (move high to mid).
Otherwise, the search range is adjusted to continue searching in the higher range (move low to mid + 1).
If the parity of target is same as the parity of low/2 then return low.
Otherwise if low is even then return low+1 otherwise return low+2.
Code:

class Solution {
public:
    int minSteps(int D)
    {
        // code here
        int target = abs(D);
        int low = 1, high = 50000;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ((long)mid * (mid + 1) / 2 >= target)
                high = mid;
            else
                low = mid + 1;
        }

        if (target % 2 == (int)ceil(low / 2.0) % 2)
            return low;

        return low % 2 == 0 ? low + 1 : low + 2;
    }
};
Complexity:
Time Complexity: O(log(d)), As the time complexity for binary search is logn.
Space Complexity: O(1), As we are using constant extra space.
Optimized Approach-2:
Intuition:
The solution uses a mathematical approach to estimate the minimum number of steps required to reach the destination. It begins by finding an initial guess for the minimum number of moves using a formula based on the sum of an arithmetic series, to find smallest integer n, such that n*(n+1)/2 >= target, or n^2 + n - 2*target >= 0, we can solve this usin ceil(sqrt(2*abs(target)+0.25) - 0.5). Then, based on whether the target is even or odd, the solution adjusts the number of moves (ans) according to the modulo result (ans % 4). These adjustments ensure that the moves account for the parity of the target and minimize the number of steps to reach the destination.

Implementation:
Calculate an initial guess for the number of moves (ans) required using the formula ceil(sqrt(2 * abs(D) + 0.25) - 0.5).
After calculating the initial guess for ans, the function adjusts the value based on the parity (odd/even) of the target D.
For even target values (D % 2 == 0):
If ans % 4 == 1, it adds 2 to ans.
If ans % 4 == 2, it adds 1 to ans.
For odd target values (D % 2 != 0):
If ans % 4 == 3, it adds 2 to ans.
If ans % 4 == 0, it adds 1 to ans.
Return ans.
Code:

class Solution {
public:
    int minSteps(int D)
    {

        int ans = ceil(sqrt(2 * abs(D) + 0.25) - 0.5);

        if (D % 2 == 0) {
            if (ans % 4 == 1)
                ans += 2;
            if (ans % 4 == 2)
                ans++;
        }
        else {
            if (ans % 4 == 3)
                ans += 2;
            if (ans % 4 == 0)
                ans++;
        }

        return ans;
    }
};
Complexity:
Time Complexity: O(sqrt(d)), As we are using sqrt function.
Space Complexity: O(1), As we are using constant extra space.
*/
