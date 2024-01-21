#include <vector>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

// this is a dense, undirected graph
// use adjacency matrix

// represents a cut edge between the MST and its complement
// see
// https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key

// TODO:
// 1. define assignment for this class
// 2. submit to leetcode, hoping TLE is solved.
// https://stackoverflow.com/questions/22437903/non-static-reference-member-cant-use-default-assignment-operator
class cutEdge
{
    const vector<vector<int>> &edgeWeights;
public:
    int a;
    int b;
    cutEdge(int a, int b, const vector<vector<int>> &edgeWeights) 
    : a(a), b(b), edgeWeights(edgeWeights) {}

    bool operator==(const cutEdge &other) const
    {
        return a == other.a && b == other.b;
    }

    bool operator<(const cutEdge other) const
    {
        return edgeWeights[a][b] < edgeWeights[other.a][other.b];
    }
};



class Solution
{
private:
    int dist(const vector<int> &a, const vector<int> &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int minCost = 0;
        int numPoints = points.size();
        vector<vector<int>> edgeWeights(numPoints, vector<int>(numPoints)); // edgeWeights[i][j] is weight between points i and j
        vector<int> a, b;                                                  // points
        for (int i = 0; i < numPoints; ++i)
        {
            for (int j = i + 1; j < numPoints; ++j)
            {
                a = points[i];
                b = points[j];

                edgeWeights[i][j] = edgeWeights[j][i] = dist(a, b);
            }
        }

        priority_queue<cutEdge> q;
        vector<bool> inMST(numPoints, false);
        int MST_size;
        inMST[0] = true;
        MST_size = 1;
        for (int j = 1; j < numPoints; j++)
        {
            cutEdge e(0, j, edgeWeights);
            q.push(e);
        }

        while (!q.empty() && MST_size < numPoints) // make sure
        {
            while (inMST[q.top().b])
            {
                q.pop();
            }
            cutEdge cur_e = q.top();
            inMST[cur_e.b] = true;
            ++MST_size;
            minCost += edgeWeights[cur_e.a][cur_e.b];
            
            for (int j = 0; j < numPoints; j++)
            {
                if (j != cur_e.b && !inMST[j])
                {
                    cutEdge e(cur_e.b, j, edgeWeights);
                    q.push(e);
                }
            }       
        }

        return minCost;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> p = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    cout << sol.minCostConnectPoints(p) << endl;

    return 0;
}

// https://stackoverflow.com/questions/9209323/easiest-way-of-using-min-priority-queue-with-key-update-in-c#
