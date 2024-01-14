#include <vector>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <iostream>
#include <functional>
using namespace std;

// this is a dense, undirected graph
// use adjacency matrix

// represents a cut edge between the MST and its complement
// see
// https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
struct cutEdge
{
    int a; // the vertex in the MST
    int b; // the vertex in the complement
    // int weight;

    bool operator==(const cutEdge &other) const
    {
        return a == other.a && b == other.b;
    }
};

template <>
struct std::hash<cutEdge>
{
    size_t operator()(const cutEdge &e) const
    {
        size_t res = 17;
        res = res * 31 + hash<int>()(e.a);
        res = res * 31 + hash<int>()(e.b);
        return res;
    }
};

struct edgeComp
{
    bool operator()(const cutEdge &lhs, const cutEdge &rhs) const
    {
        return lhs.b < rhs.b;
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
        vector<int> a, b;                                                   // points
        for (int i = 0; i < numPoints; i++)
        {
            for (int j = i + 1; j < numPoints; j++)
            {
                a = points[i];
                b = points[j];

                edgeWeights[i][j] = edgeWeights[j][i] = dist(a, b);
            }
        }

        unordered_set<cutEdge> cutSet;
        vector<bool> inMST(numPoints, false);
        int MST_size;
        inMST[0] = true;
        MST_size = 1;
        for (int j = 1; j < numPoints; j++)
        {
            cutSet.insert({0, j});
        }

        cutEdge cur_e;
        int cur_weight;
        while (!cutSet.empty() && MST_size < numPoints)
        {
            // find the minimum edge in the cut
            cur_weight = INT_MAX;
            for (auto it = cutSet.begin(); it != cutSet.end();)
            {
                if (inMST[it->b])
                {
                    it = cutSet.erase(it); // erase returns the position next to
                                           // the pointer to the removed element
                    continue;
                }

                if (edgeWeights[it->a][it->b] < cur_weight)
                {
                    cur_weight = edgeWeights[it->a][it->b];
                    cur_e = *it;
                }
                ++it;
            }

            // now cur_e is the edge we want to add in the mst
            inMST[cur_e.b] = true;
            MST_size++;
            minCost += cur_weight;

            // add edges to cut set
            for (int j = 0; j < numPoints; j++)
            {
                if (j != cur_e.b && !inMST[j])
                {
                    cutEdge new_e;
                    new_e.a = cur_e.b;
                    new_e.b = j;
                    cutSet.insert(new_e); // does not get inserted??
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
