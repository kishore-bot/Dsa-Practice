class Solution
{
public:
    int print2largest(int arr[], int n)
    {
        int largeElem = -1;
        int secondLarge = -1;
        for (auto i = 0; i < n; i++)
        {
            int x = arr[i];
            if (x > largeElem)
            {
                secondLarge = max(secondLarge, largeElem);
                largeElem = x;
            }
            if (secondLarge < x and largeElem != x)
            {
                secondLarge = max(secondLarge, x);
            }
        }
        return secondLarge;
    }
};