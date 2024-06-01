

// Takes an elem and place on its currect place

eg: 1 4 3 2 
/*
        * 1  compare with 4 , 1 is on correct place
        * 3 compare with 4 , not on corect place
            so move 4 to place ahead and plce 3 there
        * arr become 1 3 4 2
        * Now 2 , 2 not on correct place
           move 3 and 4 a place and place 2 there
        * arr 1 2 3 4
*/

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        while(i > 0 && arr[i-1] > arr[i]){
            swap(arr[i-1], arr[i]);
            i--;
        }
    }
    
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i = 0; i < n; i++){
            insert(arr, i);
        }
    } 
};

// Best case O(N) 
//Worst  O(N*N)