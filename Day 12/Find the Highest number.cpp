// Binary search on Strictly increasing and decreasing
// Easy
// https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

class Solution {
public:
    // Function to find the peak element in the given array.
    int findPeakElement(vector<int>& a) 
    {
        // Initializing left and right pointers.
        int l=0;
        int r=a.size()-1;

        // Binary search to find the peak element.
        while(l<r){
            // Calculating the mid index.
            int mid=(l+r)/2;

            // Checking if the element at mid is greater than the element on its right.
            // If yes, then the peak should be on the left side of the array.
            if(a[mid]>a[mid+1])r=mid;

            // If not, then the peak should be on the right side of the array.
            else l=mid+1;
        }

        // Returning the peak element.
        return a[l];
    }
};