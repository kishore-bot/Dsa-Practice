// MEDIUM
// GRAPH
// https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1

// not got code at this time brcause iam not reached graph but idea is check each componentes is cyclic or not



// explanation from editorial
                          
Expected Approach:
Intuition:
To solve this problem, we need to identify the connected components of the graph and check whether each component is fully connected.

To check if a component is fully connected:

Calculate the number of vertices (vertices) in the component using Depth-First Search (DFS).
Calculate the number of edges (edges) in the component using DFS.
For a component to be fully connected, the number of edges should be equal to (vertices * (vertices - 1)) / 2. This formula represents the number of edges in a complete graph with vertices vertices.
Implementation:


// Image here 

Initialize a variable ans equal to 0 and a vector visited of size V+1 with value 0.
Run a loop from 1 to V,
if the visited[i] is 0,
Initialize the variables vertices and edges equal to 0,
Call the dfs function,
The function dfs is used to traverse the graph and calculate the number of vertices and edges in each connected component.
Starting from a given vertex v, it marks the vertex as visited, increments the count of vertices, and adds the number of edges from the adjacency list of v.
The function recursively traverses the graph to explore all connected components.
Divide the number of edges by 2 to account for the undirected nature of the graph (each edge is counted twice).
Check if the number of edges matches the expected number of edges for a fully connected component using the formula (vertices * (vertices - 1)) / 2.
If the condition is met, increment the count of "good" components (ans).
Return ans.
Code:

//Back-end complete function Template for C++

class Solution {
  public:
    // DFS function to traverse the graph
    void dfs(int v, int &vertices, int &edges, vector<vector<int>> &adj,
             vector<int> &visited) {
        visited[v] = 1;
        vertices++;             // Counting the number of vertices
        edges += adj[v].size(); // Counting the number of edges
        for (auto to : adj[v]) {
            if (!visited[to]) {
                dfs(to, vertices, edges, adj, visited);
            }
        }
    }

    // Function to find the number of "good" components
    int findNumberOfGoodComponent(int E, int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V + 1, vector<int>());

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans = 0;
        vector<int> visited(V + 1, 0);

        for (int i = 1; i <= V; i++) {
            // Check if the vertex is visited or not
            if (!visited[i]) {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, adj, visited);
                // Checking if the component is "good"
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2)
                    ans++;
            }
        }
        return ans;
    }
};
Complexity:
Time Complexity: O(v + e), where v is the number of vertices and e is the number of edges. Since we traverse each connected component once, the overall time complexity is also O(v + e).
Space Complexity: O(v), for the visited array and the call stack during DFS traversal. 