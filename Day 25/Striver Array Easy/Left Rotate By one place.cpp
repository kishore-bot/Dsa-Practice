#include <bits/stdc++.h>
using namespace std;

class Solutions
{
public:
    void leftRotateByOnePlace(int arr[], int n)
    {
        int elemAt0 = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = elemAt0;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solutions sol;
        sol.leftRotateByOnePlace(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
