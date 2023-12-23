#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int find(int idx, vector<int> &parent)
    {
        // idx: location. We want to know what island
        // `location` belongs to
        // returns the representing location of the island idx belongs to
        // if idx is sea, simply return -2

        if (parent[idx] == -2)
        {
            return -2;
        }

        int p = parent[idx];
        while (p >= 0)
        {
            idx = p;
            p = parent[idx];
        }

        // add path compression here

        return idx;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> parent(m * n);

        int idx = 0; // index of a location after flattening grid

        // initialize parent
        // -1 means representative of an island, -2 means sea
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                parent[idx] = (grid[i][j] - '0') - 2;
                idx++;
            }
        }

        idx = 0;
        int rep; // representative
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                {
                    continue;
                }

                if (i >= 1 && grid[i - 1][j] == '1')
                {
                    // then (i, j) belongs to the island [i-1][j] (the location ABOVE) is in
                    if (idx - n < 0)
                        return -3;
                    rep = find(idx - n, parent);
                    if (rep == -2)
                        return -2;
                    parent[rep] = idx;
                }

                if (j >= 1 && grid[i][j - 1] == '1')
                {
                    // debugging
                    if (idx - 1 < 0)
                        return -3;
                    rep = find(idx - 1, parent);

                    // debugging
                    if (rep == -2)
                        return -2;
                    parent[rep] = idx;
                }

                idx++;
            }
        }

        int num_islands = 0;
        for (int idx = 0; idx < m * n; idx++)
        {
            if (parent[idx] == -1)
            {
                num_islands++;
            }
        }

        return num_islands;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << s.numIslands(grid) << endl;
}
