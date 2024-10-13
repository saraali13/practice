#include <iostream>
#include <vector>
using namespace std;

class HamiltonianCycle 
{
private:
    int V; // Number of vertices
    vector<vector<int>> graph;
    vector<int> path;

    bool isSafe(int v, int pos) 
{
        // Check if vertex v is adjacent to the previously added vertex
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check if the vertex has already been included in the path
        for (int i = 0; i < pos; i++) 
        {
            if (path[i] == v)
                return false;
        }

        return true;
    }

    // Utility function to solve the Hamiltonian Cycle problem
    bool hamCycleUtil(int pos) 
{
        // If all vertices are included in the path
        if (pos == V) 
        {
            // Check if there is an edge from the last vertex in the path back to the first vertex
            if (graph[path[pos - 1]][path[0]] == 1)
                return true;
            else
                return false;
        }

        // Try different vertices as the next candidate in the Hamiltonian Cycle
        for (int v = 1; v < V; v++) 
        {
            // Check if adding vertex v to the path is feasible
            if (isSafe(v, pos)) 
            {
                path[pos] = v;

                // Recur to construct the rest of the path
                if (hamCycleUtil(pos + 1))
                    return true;

                // If adding vertex v doesn't lead to a solution, remove it (backtrack)
                path[pos] = -1;
            }
        }

        return false;
    }

public:
    HamiltonianCycle(vector<vector<int>> graphInput) 
{
        graph = graphInput;
        V = graph.size();
        path.resize(V, -1);
    }

    void findHamiltonianCycle() 
{
        path[0] = 0; // Start at the first vertex

        if (hamCycleUtil(1) == false) 
        {
            cout << "No Hamiltonian Cycle exists." << endl;
        } else {
            cout << "Hamiltonian Cycle found: ";
            for (int i = 0; i < V; i++)
                cout << path[i] << " ";
            cout << path[0] << endl; // To show the cycle returns to the starting vertex
        }
    }
};

int main() 
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = 
  {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    HamiltonianCycle hc(graph);
    hc.findHamiltonianCycle();

    return 0;
}
