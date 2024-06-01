#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited,
         vector<int>& result) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; ++i) cin >> edges[i][0] >> edges[i][1];

    vector<vector<int>> graph(m);  // Danh sách kề
    vector<bool> visited(m, false);  // Đánh dấu các đỉnh đã được duyệt

    // Tạo danh sách kề từ danh sách cạnh
    for (int i = 0; i < n; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> result;  // Danh sách kết quả

    // Kiểm tra xem đỉnh 0 có tồn tại không
    if (graph[0].empty()) {
        cout << "KHONG" << endl;
        return 0;
    }

    // Thực hiện BFS từ đỉnh 0
    bfs(0, graph, visited, result);

    // Iterate until n-1 to avoid out-of-bounds access
    for (int i = 0; i < result.size() - 1; i++) {
        for (int j = i + 1; j < result.size(); j++) {
            if (result[i] > result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    // In ra tập D
    for (int vertex : result) {
        if (vertex == 0) continue;
        cout << vertex << " ";
    };
    cout << endl;

    return 0;
}
