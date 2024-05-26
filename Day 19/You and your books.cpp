// Array
// https://www.geeksforgeeks.org/problems/you-and-your-books/1

class Solution
{
public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k)
    {
        long long ans = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                res += arr[i];
                ans = max(ans, res);
            }
            else
                res = 0;
        }
        return ans;
    }
};