// Medium
// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1


// Answer of  leetcode same problem 

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 3;
    int x = 3;
    vector<int> result = sol.printKClosest(arr, n, k, x);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}


// answer for gfg
Brute Force Approach:
Intuition:
We iterate K times, each time finding the closest element to X among the remaining elements in the array. If two elements have the same difference, we select the greater element.

Implementation:
Initialize an empty vector ans to store the K closest elements.
Run a loop from 0 to k.
Initialize variables diff and val to track the minimum absolute difference and the index of the closest element found so far.
Run a loop j from 0 to n.
Check if the element is not equal to -1 (to handle elements that have been already selected) and not equal to X (as X itself is not considered).
If the absolute difference between the current element and X is less than or equal to diff, update diff with the new absolute difference and update val with the index of the current element.
Push arr[val] into the ans and update arr[val] to -1.
Return ans.
Code:

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
 
        vector<int>ans;
        
        for(int i = 0; i<k; i++){
            int diff = INT_MAX;
            int val = -1;
            for(int j = 0; j<n; j++){
                if(arr[j] != -1 && arr[j] != x){
                    if(abs(x-arr[j])<=diff){
                        diff = abs(x-arr[j]);
                        val = j;
                    }
                }
            }

            
            ans.push_back(arr[val]);
            arr[val] = -1;
        }
        
        return ans;
    
    }
};
Complexity:
Time Complexity: O(N*K), As we are running a loop of size N*K.
Space Complexity: O(K), As we have made an ans array to store K closest elements.
Brute Optimized Approach(Accepted)
Intuition:
We can use a max heap (priority_queue) to efficiently maintain the K closest elements. The max heap will contain pairs of elements where the first element is the absolute difference between the array element and X, and the second element is the negative of the array element itself.

Implementation:
Initialize a max heap maxH to store pairs of elements, where the first element is the absolute difference from X, and the second element is the negative value of the array element.
Run a loop i from 0 to n.
Skip the element if it is equal to X.
Calculate the absolute difference between the element and X.
Add a pair (absolute difference, -array element) to the max heap.
If the size of the max heap exceeds K, remove the top element from the heap.
Initialize an empty vector result to store the K closest elements.
Run a loop while the heap is not empty
Get the top element from the max heap and push the negative value of the second element in the pair.
Reverse the result array.
Return result.
Code:

class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int n, int k,
                              int x)
    {
        // code here
        priority_queue<pair<int, int> > maxH;

        for (int i = 0; i < n; i++) {
            // Skip if the element is equal to x
            if (arr[i] == x)
                continue;

            // Calculate the absolute difference and add the
            // pair to the max heap
            maxH.push({ abs(arr[i] - x), -arr[i] });

            // If the size of the max heap exceeds k, remove
            // the element with the maximum absolute
            // difference
            if (maxH.size() > k)
                maxH.pop();
        }

        // Store the result in a vector
        vector<int> result;

        // Retrieve the top k elements from the max heap
        while (!maxH.empty()) {
            // Get the top element from the max heap
            auto p = maxH.top();
            maxH.pop();

            // Add the negative value to the result vector
            result.push_back(-p.second);
        }

        // Reverse the result vector to get the closest
        // numbers in ascending order
        reverse(result.begin(), result.end());

        return result;
    }
};
Complexity:
Time Complexity: O(N*logK), As we are running a loop of size N and for adding element in the priority queue the time required is logK.
Space Complexity: O(K), As we have made an ans array and a priority queue.
Expected Approach:
Intuition:
We need to determine a crossover point in the array where elements on the left side are smaller than or equal to X, and elements on the right side are greater than X. We can use binary search to efficiently find this crossover point. Once we have the crossover point, we compare elements on the left and right sides of it to find the K closest elements to X.

Implementation:
1.png1.png
Call the findCrossOver function and store the value returned by it in a variable l.
Lets see what findCrossOver function does,
It takes four parameters: the sorted array arr, the low index low, the high index high, and the value x.
If the element at high index is less than or equal to X, return high.
If the element at low index is greater than X, return low.
find the middle point mid equal to (low + high) / 2.
If the element at mid is less than or equal to X and the element at mid + 1 is greater than X, return mid.
If the element at mid is less than X, recursively search in the right half(mid+1,right) of the array.
Otherwise, recursively search in the left half(low, mid-1) of the array.
Initialize a variable r equal to l+1 and a variable count equal to 0.
If X is present in the arr[l], decrement l to exclude it from consideration.
Initialize a vector closest,
Run a loop while l is greater than or equal to 0 and r is less than n and count is less than k,
If x - arr[l] is less than arr[r] - x then push arr[l] into the current vector and decrement l by 1.
otherwise push arr[r] into the current vector and increment r by 1.
increment count by 1.
Run a loop while count is less than k and l is greater than or equal to 0,
Push arr[l] into the current vector and decrement l by 1.
increment count by 1.
Run a loop while count is less than k and r is less than n
Push arr[r] into the current vector and increment r by 1.
ncrement count by 1.
Return the vector closest.
Code:

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> result;
        vector<int> closest;

        // Function to find the index where the array changes from values smaller to
        // values greater than x
        int l = findCrossOver(arr, 0, n - 1, x);

        int r = l + 1; // Set r as the next index
        int count = 0; // Counter for the number of closest values found

        if (arr[l] == x) { // If the value at l is equal to x, move l to the left
            l--;
        }

        // Compare the values at index l and r and select the closest value until k
        // closest values are found
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                closest.push_back(arr[l]);
                l--;
            } else {
                closest.push_back(arr[r]);
                r++;
            }
            count++;
        }

        // If k closest values are not found but there are still values to the left of l
        while (count < k && l >= 0) {
            closest.push_back(arr[l]);
            l--;
            count++;
        }

        // If k closest values are not found but there are still values to the right of
        // r
        while (count < k && r < n) {
            closest.push_back(arr[r]);
            r++;
            count++;
        }

        // Copy closest values to result vector
        for (int i = 0; i < k; i++) {
            result.push_back(closest[i]);
        }

        return result;
    }

  private:
    // Function to find the index where array changes from values smaller to values
    // greater than x
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }
};
Complexity:
Time Complexity: O(logN+K), As we find the crossover point using binary search whose complexity is logN and then we iterate through the array which count is less than K.
Space Complexity: O(K), As and array closest to store the answer.
Useful links to help you understand the concepts of this problem:

https://www.geeksforgeeks.org/find-k-closest-elements-given-value/
