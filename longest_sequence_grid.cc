#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// 由自然数组成的n*n矩阵找到最长连续整数路径并求出这个长度（每次只能向上下左右移动一格起点不限）
// the path shouldn't have loops. Otherwise, not consecutive integers

void dfs(vector<vector<int>>& grid, int x, int y, bool ascending) {
    int n = grid.size();

}

int longest_seq_len(vector<vector<int>>& grid) {
    
}

class Solution {
    bool ok(int m, int n, int i, int j) { // matrix is m * n. Location is (i, j)
        return 0 <= i && i < m && 0 <= j && j < n;
    }

    /*
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& ans, int i, int j) {
        // 
        // 

        int m = mat.size(); int n = mat[0].size();
        // ans[i][j] = 1?

        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        for (int k=0; k<4; ++k) {
            int ni = i + di[k];
            int nj = i + dj[k];
            if (ok(m, n, ni, nj) && mat[ni][nj] > mat[i][j]) {
                dfs(mat, ans, ni, nj);
                ans[ni][nj] = max(ans[ni][nj], ans[i][j] + 1);
            }
        }

        ans[i][j] = 1;
    }*/

    int dfs(const vector<vector<int>>& mat, vector<vector<int>>& memo, int i, int j) {
        // returns the length of the longest path starting from (i, j)

        if (memo[i][j] != -1) return memo[i][j];

        int res = -1;
        int m = mat.size(); int n = mat[0].size();
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        for (int k=0; k<4; ++k) {
            int ni = i + di[k];
            int nj = i + dj[k];
            if (ok(m, n, ni, nj) && mat[ni][nj] < mat[i][j]) {
                res = max(res, dfs(mat, memo, ni, nj) + 1);
                // memo[i][j] = max(memo[i][j], memo[ni][nj] + 1) ???
            }
        }

        // base case: when no neighbor (ni, nj) satisfies
        // ok(m, n, ni, nj) && mat[ni][nj] < mat[i][j],
        // then the longest increasing path starting from (i, j) must
        // have length 1. 
        if (res == -1) {
            return memo[i][j] = 1;
        }

        return memo[i][j] = res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int ans = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, dfs(matrix, memo, i, j));
                // except the very first call when (i, j) = (0, 0)
                // dfs(matrix, memo, i, j) takes O(1) time
                // thanks to memo
                //
                // Hence, this algorithm takes O(nm) time
            }
        }

        return ans;
    }
};

/*



*/
