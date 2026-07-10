#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n = 6;

    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}
    };

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return 0;
}