// Brutte
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> res;
        for (int i = 0; i < n; i++)
            res.insert(arr1[i]);
        for (int i = 0; i < m; i++)
            res.insert(arr2[i]);
        vector<int> ans;
        for (auto i : res)
            ans.push_back(i);
        return ans;
    }
};

// Optimal
{
public:
    // arr1, arr2 : the arrays
    // n, m : size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (ans.empty() || ans.back() != arr1[i])
                {
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if (ans.empty() || ans.back() != arr2[j])
                {
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }

        while (i < n)
        {
            if (ans.empty() || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }

        while (j < m)
        {
            if (ans.empty() || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }

        return ans;
    }
};