// C++ program to demonstrate Adjacency Matrix
// representation of directed and unweighted graph
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1; // Only add edge from i to j since the graph is directed
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    // Create a graph with 4 vertices and no edges
    // Note that all values are initialized as 0
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Now add edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively we can also create using below
       code if we know all edges in advance

     vector<vector<int>> mat = {{ 0, 1, 1, 0 },
                                { 0, 0, 1, 0 },
                                { 0, 0, 0, 1 },
                                { 0, 0, 0, 0 } }; */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}
