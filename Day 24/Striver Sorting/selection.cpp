



// Select min then swap with curr elem
class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        int minElemIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[minElemIndex] > arr[j]){
                minElemIndex = j;
            }
        }
        return minElemIndex;
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i = 0; i < n - 1; i++){
           int minElemIndex = select(arr, i, n);
           swap(arr[i], arr[minElemIndex]);
       }
    }
};