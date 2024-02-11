#include <bits/stdc++.h>
using namespace std;

const int NUM_VERTICES = 5;

bool isBipartiteUtil(int graph[][NUM_VERTICES], int src, int colorArr[]) {
	colorArr[src] = 1;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < NUM_VERTICES; ++v) {
			if (graph[u][v] && colorArr[v] == -1) {
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}
			else if (graph[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}
	return true;
}

bool isBipartite(int graph[][NUM_VERTICES]) {
	int colorArr[NUM_VERTICES];
	for (int i = 0; i < NUM_VERTICES; ++i)
		colorArr[i] = -1;
	for (int i = 0; i < NUM_VERTICES; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(graph, i, colorArr) == false)
				return false;
	return true;
}

bool canBeDividedInTwoCliques(int graph[][NUM_VERTICES]) {
	int complementGraph[NUM_VERTICES][NUM_VERTICES];
	for (int i = 0; i < NUM_VERTICES; i++)
		for (int j = 0; j < NUM_VERTICES; j++)
			complementGraph[i][j] = (i != j) ? !graph[i][j] : 0;
	return isBipartite(complementGraph);
}

int main() {
	int graph[NUM_VERTICES][NUM_VERTICES] = {
		{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};
	canBeDividedInTwoCliques(graph) ? cout << "Yes" : cout << "No";
	return 0;
}
