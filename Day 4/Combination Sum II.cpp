// MED REC

// https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

// https://www.youtube.com/watch?v=6fARitpO0p8&t=96s


class Solution{
public:
    
    vector<vector<int>> ans;
    void solve(vector<int>& arr, int index, vector<int>& path ,long long sum, int k) 
    {
        if(sum >= k)
        {
            if(sum == k)
                ans.push_back(path);
            
            return;
        }
        if(index >= arr.size())
        {
            return;
        }
        
        path.push_back(arr[index]);
        solve(arr, index + 1, path, sum + arr[index], k);
        path.pop_back();
        
        while(index + 1 < arr.size() && arr[index] == arr[index + 1])
            index++;
            
        solve(arr, index + 1, path, sum, k);
        
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> path;
        long long sum = 0;
        solve(arr, 0, path, sum, k);
        return ans;
    }
};