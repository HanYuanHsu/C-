#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    pair<pair<int, int>, int> maxDist(vector<vector<int>>& points, int ignore) {
        // get the maximum l1 distance for these points
        int s_max = points[0][0] + points[0][1];
        int s_min = points[0][0] + points[0][1];
        int d_max = points[0][0] - points[0][1];
        int d_min = points[0][0] - points[0][1];

        int s_min_idx = INT_MAX;
        int s_max_idx = INT_MIN;
        int d_min_idx = INT_MAX;
        int d_max_idx = INT_MIN;

        for (int i=0; i<points.size(); ++i) {
            if (i == ignore) continue;

            int s = points[i][0] + points[i][1]; // current sum
            int d = points[i][0] - points[i][1];

            if (s > s_max) {
                s_max = s;
                s_max_idx = i;
            }

            if (s < s_min) {
                s_min = s;
                s_min_idx = i;
            }

            if (d > d_max) {
                d_max = d;
                d_max_idx = i;
            }

            if (d < d_min) {
                d_min = d;
                d_min_idx = i;
            }
        }

        return s_max - s_min > d_max - d_min ? 
            make_pair(make_pair(s_min_idx, s_max_idx), s_max - s_min) : 
            make_pair(make_pair(d_min_idx, d_max_idx), d_max - d_min);
    }

    int minimumDistance(vector<vector<int>>& points) {
        pair<pair<int, int>, int> info = maxDist(points, -1);
        int min_idx = info.first.first;
        int max_idx = info.first.second;
        return min(maxDist(points, min_idx).second, maxDist(points, max_idx).second);
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> points = {
        {3, 2},
        {3, 9},
        {7, 10},
        {4, 4},
        {8, 10},
        {2, 7}
    };
    pair<pair<int, int>, int> info = sol.maxDist(points, -1);
    cout << info.first.first << endl;
    cout << info.first.second << endl;
    cout << info.second << endl;

    return 0;
}
