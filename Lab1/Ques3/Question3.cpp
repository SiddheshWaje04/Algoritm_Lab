#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Represents infinity

// Function to calculate total distance for a permutation
int calculateDistance(const vector<vector<int>> &graph, const vector<int> &path)
{
    int distance = 0;
    int n = graph.size();

    for (int i = 0; i < n - 1; ++i)
    {
        if (graph[path[i]][path[i + 1]] == INF)
        {
            return INF; // If cities are not connected, return infinity
        }
        distance += graph[path[i]][path[i + 1]];
    }

    if (graph[path[n - 1]][path[0]] == INF)
    {
        return INF; // Return infinity if the last city is not connected to the starting city
    }
    distance += graph[path[n - 1]][path[0]]; // Return to the starting city
    return distance;
}

// Function to solve the Traveling Salesman Problem using brute force
int solveTSP(const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> path(n);
    for (int i = 0; i < n; ++i)
    {
        path[i] = i; // Initialize the path with cities
    }

    int minDistance = INF;
    do
    {
        int distance = calculateDistance(graph, path);
        minDistance = min(minDistance, distance);
    } while (next_permutation(path.begin() + 1, path.end())); // Start from the second city

    return minDistance;
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    // Reading input from input.txt
    int n;
    inputFile >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inputFile >> graph[i][j];
        }
    }

    int shortestDistance = solveTSP(graph);

    // Writing output to output.txt
    if (shortestDistance == INF)
    {
        outputFile << "No possible route visiting all cities exactly once." << endl;
    }
    else
    {
        outputFile << "Shortest possible route distance: " << shortestDistance << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
