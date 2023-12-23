#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    struct neighbor
    {
        string vertex;
        double weight; // weight of the edge to this neighbor
    };

    unordered_map<string, vector<neighbor>> adjacencyList;

    void dfs(const string &start, const string &end, double &product, set<string> &visited, bool &can_find /*=false*/)
    {
        if (start == end)
        {
            can_find = true;
            return;
        }

        visited.insert(start);

        for (const neighbor &n : adjacencyList[start])
        {
            if (visited.find(n.vertex) == visited.end())
            { // if the neighbor has not been visited
                product *= n.weight;
                dfs(n.vertex, end, product, visited, can_find);
            }
        }
    }

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

    bool dfs(const string &start, const string &end, double &product)
    {
        // returns true if can evaluate start / end
        // false otherwise

        set<string> visited;
        bool can_find = false;

        dfs(start, end, product, visited, can_find);

        return can_find;
    }
};

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    // [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"]]
    //
    // a = 2 * b, b = 3 * c

    // draw a graph where the edge from a to b has weight 2, the edge from b to a has weight 1/2, etc
    // also, a

    int n = equations.size();
    Graph G = Graph();
    vector<double> result;

    for (int i = 0; i < n; i++)
    {
        G.addEdge(equations[i], values[i]); // ["a","b"], 2.0
    }

    double product;
    bool can_find;
    for (const vector<string> &q : queries)
    {
        product = 1;
        can_find = G.dfs(q[0], q[1], product);
        if (can_find)
        {
            result.push_back(product);
        }
        else
        {
            result.push_back(-1.0);
        }
    }

    return result;
}

void test()
{
    // [["a","b"],["b","c"]], values = [2.0, 3.0]
    Graph G = Graph();
    G.addEdge({"a", "b"}, 2.0);
    G.addEdge({"b", "c"}, 3.0);

    double result = 1.0;
    bool can_find = G.dfs("b", "a", result);

    cout << "Can find: " << can_find << endl;
    cout << result << endl;
}

int main()
{
    /*
    Graph G = Graph();
    G.addEdge({"a", "b"}, 1.5);
    G.addEdge({"b", "c"}, 2.5);
    G.addEdge({"bc", "cd"}, 5.0);

    double result = 1.0;
    bool can_find = G.dfs("a", "c", result);

    cout << "Can find: " << can_find << endl;
    cout << result << endl;
    */

    test();

    return 0;
}
