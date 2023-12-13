#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;

class Graph
{
private:
    struct vertex
    {
        string name;
        double value; // will store (starting vertex / this vertex)
    };
    vertex newVertex(const string &name)
    {
        vertex v;
        v.name = name;
        return v;
    }

    struct neighbor
    {
        vertex vtx;
        double weight; // weight of the edge to this neighbor
    };

    unordered_map<vertex, vector<neighbor>> adjacencyList;

public:
    void addEdge(const vector<string> &equation, double value)
    {
        // e.g. addEdge(["a", "b"], 2.0) will add 2 from a to b and 1/2 from b to a
        neighbor n;
        n.vtx = newVertex(equation[1]);
        n.weight = value;
        adjacencyList[].push_back(n);

        n.vertex = equation[0];
        n.weight = 1 / value;
        adjacencyList[equation[1]].push_back(n);
    }

    /**
     * returns true if can evaluate start / end, otherwise false
     */
    bool bfs(string &start, string &end, double product /*=1.0*/)
    {
        set<string> visited;
        deque<string> fringe = {start};

        string current_vertex;
        while (!fringe.empty())
        {
            current_vertex = fringe.front();
            fringe.pop_front();
            visited.insert(current_vertex);

            // add vertices to be visited into the queue
            for (neighbor &n : adjacencyList[current_vertex])
            {
                if (visited.find(n.vertex) == visited.end()) // if n.vertex is not yet visited
                {
                    fringe.push_back(n.vertex);
                }
            }
        }
    }
};
