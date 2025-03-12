## Documentation

### bfs

This C++ code implements a Breadth-First Search (BFS) algorithm to traverse a graph. Let's break down the code section by section:

### Includes and Namespace
```cpp
#include <iostream>
#include <vector>
#include <queue>
```
- `#include <iostream>`: This header is included to allow the program to perform input and output operations using `std::cout` and `std::cerr`.
- `#include <vector>`: This header is included to use the `std::vector` container which dynamically resizes as needed.
- `#include <queue>`: This header is included to use the `std::queue` container, which provides a first-in-first-out (FIFO) data structure needed for the BFS algorithm.

### BFS Function
```cpp
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
```
- **Function Signature**: `void BFS(int start, const std::vector<std::vector<int>>& graph)` defines a BFS function that takes a starting node `start` and a graph represented as an adjacency list (`graph`).
- **Bounds Checking**: The function first checks if the `start` node is valid (within the bounds of the graph). If not, it prints an error message and returns.
- **Visited Vector**: `std::vector<bool> visited(graph.size(), false)` initializes a vector of boolean values to keep track of which nodes have been visited. All values are initially set to `false`.
- **Queue Initialization**: A queue is created to facilitate the BFS. The starting node is pushed onto the queue, and it is marked as visited (`visited[start] = true`).
- **BFS Loop**: The core of the BFS algorithm is a loop that continues until the queue is empty:
  - The front element of the queue (current node) is retrieved and removed.
  - The current node is printed as visited.
  - For each neighbor of the current node (retrieved from the adjacency list), if the neighbor has not been visited, it is marked as visited and added to the queue.

### Main Function
```cpp
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
```
- **Graph Definition**: A graph is defined using a vector of vectors, where each inner vector represents the neighbors of a node:
  - Node 0 is connected to nodes 1 and 2.
  - Node 1 is connected to nodes 0, 3, and 4.
  - Node 2 is connected to node 0.
  - Node 3 is connected to node 1.
  - Node 4 is connected to node 1.
- **Calling BFS**: The BFS function is called with the starting node `0` and the defined graph.
- **Return Statement**: The program returns `0`, indicating successful completion.

### Summary
This code performs a Breadth-First Search on a simple undirected graph starting from a specified node. It prints out the nodes in the order they are visited, demonstrating the BFS traversal pattern, which explores neighbors level by level.



![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
