#include <iostream>
#include <vector>
using namespace std;

class GraphColoring 
{
private:
    int V; // Number of vertices
    vector<vector<int>> graph;
    vector<int> colors;

    // Check if the current color assignment is safe for vertex v
    bool isSafe(int v, int c) 
{
        for (int i = 0; i < V; i++) 
        {
            if (graph[v][i] == 1 && colors[i] == c) // If adjacent vertex has the same color
                return false;
        }
        return true;
    }

    // Utility function to solve the graph coloring problem
    bool graphColoringUtil(int v, int m) 
{
        // If all vertices are assigned a color, return true
        if (v == V)
            return true;

        // Try different colors for vertex v
        for (int c = 1; c <= m; c++) 
        {
            // Check if assignment of color c to vertex v is safe
            if (isSafe(v, c)) 
            {
                colors[v] = c;

                // Recur to assign colors to the remaining vertices
                if (graphColoringUtil(v + 1, m))
                    return true;

                // If assigning color c doesn't lead to a solution, remove it (backtrack)
                colors[v] = 0;
            }
        }
        return false;
    }

public:
    GraphColoring(vector<vector<int>> graphInput) 
{
        graph = graphInput;
        V = graph.size();
        colors.resize(V, 0);
    }

    void solve(int m) 
{
        if (graphColoringUtil(0, m)) 
        {
            cout << "Solution exists with " << m << " colors:" << endl;
            for (int i = 0; i < V; i++) 
            {
                cout << "Vertex " << i << " --> Color " << colors[i] << endl;
            }
        } 
        else 
        {
            cout << "No solution exists with " << m << " colors." << endl;
        }
    }
};

int main() 
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = 
  {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    GraphColoring gc(graph);
    int m = 3; // Number of colors
    gc.solve(m);

    return 0;
}
