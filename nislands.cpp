#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    void bfs(vector<vector<char>> &grid, int start_idx, set<int> &visited)
    {
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        set<int> visited; // stores the locations that are visited

        int m = grid.size();
        int n = grid[0].size();
        int idx = 0;
        int cur_idx;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                queue<int> q;
                q.push(idx);
                while (!q.empty())
                {
                    cur_idx = q.front();
                    q.pop();
                    if (grid
                    visited.insert(cur_idx);
                    
                    // add its neighbors in the queue
                    if (idx )
                }
                idx++;
            }
        }
    }
};
