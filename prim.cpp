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
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    //  The vertices are 0, 1, 2, ..., V-1
    //  adj[i] contains vectors of size 2, where the first element in that vector
    //  denotes the end of the edge (neighbor vertex)
    //  and the second element denotes the weight of the edge
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> distTo;
        for (int i = 0; i < V; i++)
        {
            distTo.push_back(INT_MAX);
        }
        distTo[0] = 0;

        vector<int> mst; // mst represents the minimal spanning tree
        // mst[i] is the parent of i
        // the parent of the root is -1
        for (int i = 0; i < V; i++)
        {
            mst.push_back(-1);
        }

        set<vector<int>> fringe; // stores all edges (a, b, weight) of the MST that is forming
        }
};
