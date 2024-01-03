#include <vector>
#include <iostream>
#include <set>
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

        return idx;
    }

    void union_land(int i, int j, vector<int> &parent)
    {
        if (parent[i] == -2 || parent[j] == -2)
        {
            return;
        }

        parent[j] = find(i, parent);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> parent;

        int idx = 0; // index of a location after flattening grid

        // initialize parent
        // -1 means representative of an island, -2 means sea
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                parent.push_back((grid[i][j] - '0') - 2);
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
                    union_land(idx - n, idx, parent);
                }

                if (j >= 1 && grid[i][j - 1] == '1')
                {
                    union_land(idx - 1, idx, parent);
                }

                idx++;
            }
        }

        set<int> s;
        idx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    s.insert(find(idx, parent));
                }

                idx++;
            }
        }

        /*
        for (auto &elm : s)
        {
            cout << elm << endl;
        }
        */

        idx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << parent[idx] << " ";

                idx++;
            }
            cout << endl;
        }

        return s.size();
    }
};

int main()
{
    Solution s;

    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << s.numIslands(grid1) << endl;
}

// https://stackoverflow.com/questions/70676083/returning-the-right-number-of-islands-using-union-find
