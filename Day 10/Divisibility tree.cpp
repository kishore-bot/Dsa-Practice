
// Dfs
// Medium
// https://www.geeksforgeeks.org/problems/divisibility-tree1902/1



#include <vector>
using namespace std;

class Solution {
private:
    int dfs(vector<int> adj[], vector<int>& vis, int i, int& ans) {
        vis[i] = 1;
        int cnt = 1;  // Starting count as 1 to include the node itself
        for (auto it : adj[i]) {
            if (!vis[it]) {
                int res = dfs(adj, vis, it, ans);
                if (res % 2 == 0) {
                    ans++;
                } else {
                    cnt += res;
                }
            }
        }
        return cnt;
    }

public:
    int minimumEdgeRemove(int n, vector<vector<int>> edges) {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        vector<int> vis(n, 0);

        int ans = 0;
        dfs(adj, vis, 0, ans);
        return ans;
    }
};
// https://www.youtube.com/watch?v=bmHq0qYDlnQ