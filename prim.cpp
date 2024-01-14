#include <vector>
#include <set>
using namespace std;

/* ignore this Graph class */
class Graph
{
private:
    struct neighbor
    {
        int vertex;
        double weight; // weight of the edge to this neighbor
    };

    vector<neighbor> adjacencyList;

public:
};

class Solution
{
private:
    // A utility function to find the vertex with
    // minimum key value, from the set of vertices
    // not yet included in MST
    int minKey(int V, vector<int> &key, vector<bool> &mstSet)
    {
        int weight = INT_MAX, min_index;
        for (int i = 0; i < V; i++)
        {
            if (!mstSet[i] && key[i] < weight)
            {
                weight = key[i];
                min_index = i;
            }
        }

        return min_index;
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    //  The vertices are 0, 1, 2, ..., V-1
    //  adj[i] contains vectors of size 2, where the first element in that vector
    //  denotes the end of the edge (neighbor vertex)
    //  and the second element denotes the weight of the edge
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key;     // key[i] is the minimum edge weight in cut.
        vector<bool> mstSet; // mstSet[i] tells you whether vertex i is in the mst

        for (int i = 0; i < V; i++)
        {
            key.push_back(INT_MAX);
            mstSet.push_back(false);
        }
        key[0] = 0;
        mstSet[0] = true;

        vector<int> mst(V); // mst represents the minimal spanning tree
        // mst[i] is the parent of i
        // the parent of the root is -1
        mst[0] = -1;

        // currently, the MST is only one node 0.
        int u = minKey(V, key, mstSet);
        mst[u] = 0;
        mstSet[u] = true;

        // set<vector<int>> fringe; // stores all edges (a, b, weight) of the MST that is forming
        // in the cut
    }
};
