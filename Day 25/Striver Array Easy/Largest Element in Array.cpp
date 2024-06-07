// Array
// Easy

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int largeElem = 0;
        for (auto i : arr)
        {
            largeElem = max(largeElem, i);
        }
        return largeElem;
    }
};