#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;

class Graph
{
private:
    struct neighbor
    {
        string vertex;
        double weight; // weight of the edge to this neighbor
    };

    struct queue_pair
    {
        string vertex;
        double product; // stores the evaluataion (start / this vertex)
    };

    unordered_map<string, vector<neighbor>> adjacencyList;

public:
    void addEdge(const vector<string> &equation, double value)
    {
        // e.g. addEdge(["a", "b"], 2.0) will add 2 from a to b and 1/2 from b to a
        neighbor n;
        n.vertex = equation[1];
        n.weight = value;
        adjacencyList[equation[0]].push_back(n);

        n.vertex = equation[0];
        n.weight = 1 / value;
        adjacencyList[equation[1]].push_back(n);
    }

    double bfs(string &start, string &end)
    {
        // returns the evaluation start / end or -1.0 if things don't work

        set<string> visited;
        deque<queue_pair> fringe = {{start, 1}};

        if (adjacencyList.find(start) == adjacencyList.end() || adjacencyList.find(end) == adjacencyList.end())
        {
            // couldn't evaluate
            return -1.0;
        }

        while (!fringe.empty())
        {
            auto [v, prod] = fringe.front();
            fringe.pop_front();
            visited.insert(v);

            if (v == end)
            {
                return prod;
            }

            for (const neighbor &nei : adjacencyList[v])
            {
                if (visited.find(nei.vertex) == visited.end())
                {
                    fringe.push_back({nei.vertex, prod * nei.weight});
                }
            }
        }

        return -1.0;
    }
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = values.size();
        Graph G;
        vector<double> result;

        for (int i = 0; i < n; i++)
        {
            G.addEdge(equations[i], values[i]);
        }

        for (auto &query : queries) // query is of the form [start, end]
        {
            result.push_back(G.bfs(query[0], query[1]));
        }

        return result;
    }
};
