
#include <iostream>
#include <vector>
#include <queue>

void BFS(int start, const std::vector<std::vector<int>>& graph) {
    if (start < 0 || start >= graph.size()) {
        std::cerr << "Start node is out of bounds." << std::endl;
        return;
    }

    std::vector<bool> visited(graph.size(), false);
    std::queue<int> queue;

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        std::cout << "Visited: " << node << std::endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1, 2},    // Connections for node 0
        {0, 3, 4}, // Connections for node 1
        {0},       // Connections for node 2
        {1},       // Connections for node 3
        {1}        // Connections for node 4
    };

    // Start BFS from node 0
    BFS(0, graph); 
    return 0;
}

