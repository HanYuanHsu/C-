#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
public:
    int numIslands(vector<vector<char>> &grid)
    {
        set<pair<int, int>> visited; // stores the locations that are visited

        int m = grid.size();
        int n = grid[0].size();
        // int idx = 0;
        bool not_visited;
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                not_visited = visited.find(make_pair(i, j)) == visited.end();
                if (grid[i][j] == '1' && not_visited)
                {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));

                    while (!q.empty())
                    {
                        auto [cur_i, cur_j] = q.front();
                        q.pop();
                        visited.insert(make_pair(cur_i, cur_j));

                        not_visited = visited.find(make_pair(cur_i, cur_j + 1)) == visited.end();
                        if (cur_j + 1 < n && grid[cur_i][cur_j + 1] == '1' && not_visited)
                        {
                            q.push(make_pair(cur_i, cur_j + 1));
                        }

                        not_visited = visited.find(make_pair(cur_i, cur_j - 1)) == visited.end();
                        if (cur_j - 1 >= 0 && grid[cur_i][cur_j - 1] == '1' && not_visited)
                        {
                            q.push(make_pair(cur_i, cur_j - 1));
                        }

                        not_visited = visited.find(make_pair(cur_i + 1, cur_j)) == visited.end();
                        if (cur_i + 1 < m && grid[cur_i + 1][cur_j] == '1' && not_visited)
                        {
                            q.push(make_pair(cur_i + 1, cur_j));
                        }

                        not_visited = visited.find(make_pair(cur_i - 1, cur_j)) == visited.end();
                        if (cur_i - 1 >= 0 && grid[cur_i - 1][cur_j] == '1' && not_visited)
                        {
                            q.push(make_pair(cur_i - 1, cur_j));
                        }
                    }

                    count++;
                }
            }
        }

        return count;
    }
};
