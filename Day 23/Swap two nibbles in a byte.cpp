// Eaasy
// Bit Manipulation
//https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

// Optimal

class Solution
{
public:
    int swapNibbles(int n)
    {
        int arr[8];

        // Extract the bits of the number
        for (int i = 0; i < 8; i++)
        {
            arr[i] = n % 2;
            n /= 2;
        }

        // Swap the nibbles: first four bits with the last four bits
        std::reverse(arr, arr + 4);
        std::reverse(arr + 4, arr + 8);
        std::reverse(arr, arr + 8);

        // Reconstruct the number from the array
        int ans = 0, powe = 1;
        for (int i = 0; i < 8; i++)
        {
            ans += arr[i] * powe;
            powe *= 2;
        }

        return ans;
    }
};

// Super Optimal
class Solution
{
public:
    int swapNibbles(int n)
    {
        int ans = n & 15; // 15 rep as 1111
        // eg n = .....0010 0001 we need first 4 bits(0010) so and with 15 make 0010 rest of them get 0's
        ans <<= 4;
        int b = n >> 4;
        return ans | b;
    }
};
