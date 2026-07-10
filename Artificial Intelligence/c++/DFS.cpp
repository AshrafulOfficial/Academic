#include <iostream>
#include <vector>
#include <stack>
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
    stack<int> st;

    st.push(0);

    cout << "DFS Traversal: ";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int i = graph[node].size() - 1; i >= 0; i--) {
                int neighbor = graph[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }

    return 0;
}