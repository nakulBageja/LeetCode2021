/**
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/

int dir[5] = {-1, 0, 1, 0, -1};

class Solution
{
public:
    int R, C;
    vector<vector<int>> m;
    void dfs(vector<vector<int>> &v, int r, int c, int maxi)
    {
        v[r][c] = 1;
        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d];
            int dc = c + dir[d + 1];
            if (dr < 0 || dr >= R || dc < 0 || dc >= C || v[dr][dc])
                continue;
            int diff = abs(m[r][c] - m[dr][dc]);
            // if the current move is above the threshold, skip
            if (diff > maxi)
                continue;
            dfs(v, dr, dc, maxi);
        }
    }

    int minimumEffortPath(vector<vector<int>> &m)
    {
        this->m = m;
        this->R = m.size(), this->C = R ? m[0].size() : 0;
        int l = 0, r = 1e6;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            vector<vector<int>> v(R, vector<int>(C, 0));
            dfs(v, 0, 0, mid);
            if (v[R - 1][C - 1])
            {
                // if we reach the end, try a smaller maxi
                r = mid;
            }
            else
            {
                // if we can't reach the end, try a larger maxi
                l = mid + 1;
            }
        }
        return l;
    }
};