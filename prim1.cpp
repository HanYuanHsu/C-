#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
private:
    // represents a cut edge between the MST and its complement
    struct cutEdge
    {
        int a; // the vertex in the MST
        int b; // the vertex in the complement
        int weight;
    };

public:
    //  Function to find sum of weights of edges of the Minimum Spanning Tree.
    //  The vertices are 0, 1, 2, ..., V-1
    //  adj[i] contains vectors of size 2, where the first element in that vector
    //  denotes the end of the edge (neighbor vertex)
    //  and the second element denotes the weight of the edge
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> mst(V); // mst represents the minimal spanning tree
        // mst[i] is the parent of i
        // the parent of the root is -1
        // when mst[i] is -2, it means i is not part of the mst
        for (int i = 0; i < V; i++)
        {
            mst[i] = -2;
        }
        mst[0] = -1;

        set<cutEdge> cutSet;

        int minWeight;
        int neigh, w; // neighbor vertex, weight
        int weightSum = 0;

        for (const auto &x : adj[0])
        {
            neigh = x[0];
            w = x[1];
            cutSet.insert({0, neigh, w});
        }

        cutEdge curCutEdge;
        while (!cutSet.empty())
        {
            // find the minimum edge in the cut
            minWeight = INT_MAX;
            for (const cutEdge &e : cutSet)
            {
                // if the edge e is no longer a valid cut edge
                // i.e. e.b is in the MST, causing a cycle,
                // then remove it
                if (mst[e.b] != -2)
                {
                    cutSet.erase(e);
                    continue;
                }

                if (e.weight < minWeight)
                {
                    minWeight = e.weight;
                    curCutEdge = e;
                }
            }

            mst[curCutEdge.b] = curCutEdge.a;
            weightSum += curCutEdge.weight;

            for (const auto &x : adj[curCutEdge.b])
            {
                neigh = x[0];
                w = x[1];
                if (mst[neigh] == -2)
                {
                    cutSet.insert({curCutEdge.b, neigh, w});
                }
            }
        }

        return weightSum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[] = {};
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
