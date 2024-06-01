

// compare adjacent elem if they are not on correct place make it
//  by doing this the largest elem become on last like that

// eg 1  5  3 2
/*
    * On first loop
       swap 5 and 3
       become 1 3 5 2
       swap 5 2
       becomes 1 3 2 5

    * On Second Loop
     swap 3 and 2
     become 1 2 3 5
*/
// large elem get push to last index based on thier size

//  best and worst  O(n*n)
class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

//  best O(n), worst  O(n*n)
class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            bool didSwap = 0;
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    didSwap = 1;
                }
            }
            if (didSwap == 0)
                break;
        }
    }
};

/*
        eg : 1 2 3 4 5
        it breaks first loop (i = 5 ,j runs one time)

*/