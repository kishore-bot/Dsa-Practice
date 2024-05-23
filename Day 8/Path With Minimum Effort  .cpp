// Not got
// BFS or DFs and matrix
// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

Editorial
    Expected Approach : Intuition : We will use binary search on the possible range of effort values,
                                    then use a BFS traversal to check if a given effort value allows traversal from start to end.

                                        Implementation : minimumEffort
                                                             Initialize the variables l and h equal to 0 and
                                        1e6 respectively.Run a loop while l is less than h,
                                    Initialize a variable mid equal to(l + (h - l) / 2).Call the check function,
                                    Let's see what check function does, n and m are initialized to represent the number of rows and columns in the grid, respectively.A boolean 2D array(vis) is initialized to keep track of the cells that have been visited during the traversal.All cells are initially marked as not visited(false).A queue(q)
is initialized to hold the cells to be processed during the BFS traversal.The starting cell(0, 0) is pushed onto the queue, and it is marked as visited in the vis array.Run a loop while queue is not emp
                                                                                                                                The function dequeues the front cell(temp)
from the queue.If the dequeued cell is the destination cell(n - 1, m - 1), the function returns true because a feasible path from the start to the end has been found under the given effort(mid).The function uses two arrays(xdir and ydir) to represent the four possible directions to move from the current cell(right, down, left, up).For each possible direction, the function calculates the coordinates(x, y) of the neighboring cell.
If the neighboring cell is within the bounds of the grid, not visited yet, and the absolute difference in height between the current cell and the neighboring cell is less than or equal to mid, the neighboring cell is considered feasible to visit.
If a neighboring cell satisfies the conditions (within bounds, not visited, and effort difference within limit), it is marked as visited in the vis array.
The feasible neighboring cell is then pushed onto the queue for further processing.
Return false.
Code:

class Solution
{
public:
    // Function to check if the given mid value is feasible or not.
    bool check(vector<vector<int>> &a, int mid)
    {
        int n = a.size();
        int m = a[0].size();

        // Creating a boolean matrix to keep track of visited cells.
        bool vis[n][m];
        memset(vis, false, sizeof(vis));

        queue<pair<int, int>> q;

        // Pushing the starting cell into the queue and marking it as visited.
        q.push({0, 0});
        vis[0][0] = true;

        // Arrays to store the x and y directions for neighboring cells.
        vector<int> xdir = {1, 0, -1, 0};
        vector<int> ydir = {0, -1, 0, 1};

        // BFS traversal of the matrix.
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            // If we reach the destination cell, return true.
            if (temp.first == n - 1 && temp.second == m - 1)
                return true;

            // Checking the neighboring cells and pushing them into the queue if valid.
            for (int k = 0; k < 4; ++k)
            {
                int x = temp.first + xdir[k];
                int y = temp.second + ydir[k];

                // If the neighboring cell is out of bounds or already visited or the
                // difference in effort between the neighboring cell and the current
                // cell is greater than the mid value, skip it.
                if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] ||
                    abs(a[x][y] - a[temp.first][temp.second]) > mid)
                    continue;

                // Pushing the valid neighboring cell into the queue and marking it as
                // visited.
                q.push({x, y});
                vis[x][y] = true;
            }
        }

        return false; // If we reach here, it means we couldn't reach the destination
                      // cell with the given mid value.
    }

    // Function to find the minimum effort required to reach the bottom-right cell from
    // the top-left cell.
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        int l = 0, h = 1e6;

        // Binary search to find the minimum effort.
        while (l < h)
        {
            int mid = l + (h - l) / 2;

            // Checking if the mid value is feasible or not by using BFS.
            if (check(heights, mid))
                h = mid; // If feasible, update the high value
            else
                l = mid + 1; // If not feasible, update the low value
        }

        return l; // Returning the minimum effort.
    }
};
Complexity:
Time Complexity: O(n*m*log(1e6)), As we are using binary search for the various effort values and for each value we are traversing the whole matrix, where n is the number of rows and m is the number of columns.
Space Complexity: O(n*m), As we have made a visited array of size n*m and a queue, where n is the number of rows and m is the number of columns.
Alternate Approach:
Intuition:
We use Dijkstra's algorithm, prioritizing cells with the least effort (maximum absolute difference) and exploring them first to find the minimum effort path to the destination.

Implementation:
The function initializes a priority queue (pq)
to store cells in the grid with their respective maximum effort from the starting cell.A distance matrix(d)
is used to keep track of the minimum effort required to reach each cell.Initially, all cells are set to a high value(1e9), except the starting cell, which is set to 0. The starting cell(0, 0) is added to the priority queue with an effort of 0. Run a loop while priority queue is not empty The function dequeues the top cell from the priority queue, which represents the current cell with the minimum effort.If the dequeued cell is the bottom - right cell(destination), the function returns the effort associated with this cell as it is the minimum effort path found.The function uses four directions(up, down, left, right)
to explore neighboring cells.For each direction, it calculates the coordinates of the neighboring cell.If the neighboring cell is within the grid bounds, the function calculates the maximum absolute difference(nf)
between the heights of the current cell and the neighboring cell and the current effort(diff).If the calculated effort(nf) is less than the recorded effort in the distance matrix (d) for the neighboring cell, the function updates the distance matrix and adds the neighboring cell to the priority queue with the updated effort.
Return -1.
Code:

class Solution
{
public:
    int MinimumEffort(int rows, int columns,
                      vector<vector<int>> &heights)
    {
        // code here
        int N = heights.size(), M = heights[0].size();

        // priority queue containing pairs of cells and
        // their respective distance from the source cell in
        // the form {diff, {row of cell, col of cell}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        // distance matrix with initially all the cells
        // marked as unvisited
        vector<vector<int>> d(N, vector<int>(M, 1e9));
        // distance for source cell (0,0) is 0
        d[0][0] = 0;
        pq.push({0, {0, 0}});

        // array to traverse in all four directions
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the
        // elements out of the queue and pushing whenever a
        // shorter distance to a cell is found
        while (!pq.empty())
        {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            // return the current value of difference (which
            // will be min) if we reach the destination
            if (r == N - 1 && c == M - 1)
                return diff;
            for (int i = 0; i < 4; i++)
            {
                // r-1, c
                // r, c+1
                // r-1, c
                // r, c-1
                int nx = dx[i] + r;
                int ny = dy[i] + c;

                // checking validity of the cell
                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                {
                    // effort can be calculated as the max
                    // value of differences between the
                    // values of the node and its adjacent
                    // nodes
                    int nf = max(abs(heights[r][c] - heights[nx][ny]),
                                 diff);

                    // if the calculated effort is less than
                    // the prev value update as we need the
                    // min effort
                    if (nf < d[nx][ny])
                    {
                        d[nx][ny] = nf;
                        pq.push({nf, {nx, ny}});
                    }
                }
            }
        }
        // if unreachable
        return -1;
    }
};
Complexity : Time Complexity : O(n *m *log(n *m)), The time complexity of Dijkstra’s algorithm is O((V + E) log V), where V is the number of vertices and E is the number of edges.In this case, V is n *m(the total number of cells), and E is approximately 4 * n *m(each cell is connected to its four neighbors).Therefore, the time complexity is O(n *m *log(n *m)).Space Complexity:
O(n *m), As we have made a matrix d and a priority queue.

// code from comment
int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
{
    // code here4
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    int mini = INT_MAX;
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    vector<vector<int>> visited(rows, vector<int>(columns, 0));
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int maxi = temp[0];
        int r = temp[1];
        int c = temp[2];
        if (r == rows - 1 and c == columns - 1)
            return maxi;
        if (visited[r][c])
            continue;
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 and nr < rows and nc >= 0 and nc < columns && !visited[nr][nc])
            {
                int t = abs(heights[r][c] - heights[nr][nc]);
                t = max(t, maxi);
                pq.push({t, nr, nc});
            }
        }
    }
    return 0;
}