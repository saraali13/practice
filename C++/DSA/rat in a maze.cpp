#include <iostream>
using namespace std;

#define N 5 // Dimension of the maze

bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    // Check if x, y is within the maze boundaries and path is open
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // If destination is reached
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if the current move is safe
    if (isSafe(maze, x, y, sol)) {
        // Mark the current cell as part of the solution path
        sol[x][y] = 1;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // Move up
        if (solveMazeUtil(maze, x - 1, y, sol))
            return true;

        // Move left
        if (solveMazeUtil(maze, x, y - 1, sol))
            return true;

        // Backtrack: unmark the cell as part of the solution path
        sol[x][y] = 0;
    }
    return false;
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0 } }; // Initialize the solution matrix

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No solution exists" << endl;
        return false;
    }

    printSolution(sol);
    return true;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
