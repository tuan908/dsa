#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to check if two graphs are isomorphic using BFS
bool areIsomorphicBFS(int n, const vector<vector<int>>& G1,
                      const vector<vector<int>>& G2, vector<int>& mapG1toG2) {
    vector<bool> visited1(n, false);
    vector<bool> visited2(n, false);
    queue<int> q1, q2;

    // Start from the first node in both graphs
    q1.push(0);
    q2.push(0);
    visited1[0] = true;
    visited2[0] = true;
    mapG1toG2[0] = 0;

    while (!q1.empty() && !q2.empty()) {
        int node1 = q1.front();
        int node2 = q2.front();
        q1.pop();
        q2.pop();

        // Collect all neighbors
        vector<int> neighbors1, neighbors2;
        for (int i = 0; i < n; ++i) {
            if (G1[node1][i] == 1 && !visited1[i]) {
                neighbors1.push_back(i);
                visited1[i] = true;
            }
            if (G2[node2][i] == 1 && !visited2[i]) {
                neighbors2.push_back(i);
                visited2[i] = true;
            }
        }

        // Sort neighbors to ensure the order doesn't affect the result
        sort(neighbors1.begin(), neighbors1.end());
        sort(neighbors2.begin(), neighbors2.end());

        if (neighbors1.size() != neighbors2.size()) {
            return false;
        }

        // Map neighbors1 to neighbors2
        for (size_t i = 0; i < neighbors1.size(); ++i) {
            int u = neighbors1[i];
            int v = neighbors2[i];
            mapG1toG2[u] = v;
            q1.push(u);
            q2.push(v);
        }
    }

    return true;
}

bool areIsomorphic(int n, const vector<vector<int>>& G1,
                   const vector<vector<int>>& G2) {
    vector<int> mapG1toG2(n, -1);
    return areIsomorphicBFS(n, G1, G2, mapG1toG2);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G1(n, vector<int>(n));
    vector<vector<int>> G2(n, vector<int>(n));

    // Read the first adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G1[i][j];
        }
    }

    // Read the second adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G2[i][j];
        }
    }

    vector<int> mapG1toG2(n, -1);

    if (areIsomorphic(n, G1, G2)) {
        cout << "Hai do thi dang cau.\n";
        cout << "Song anh giua cac dinh la:\n";
        for (int i = 0; i < n; ++i) {
            cout << i << " -> " << mapG1toG2[i] << endl;
        }
    } else {
        cout << "Hai do thi khong dang cau.\n";
    }

    return 0;
}