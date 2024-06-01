#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& reachable) {
    queue<int> q;
    q.push(start);
    reachable[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Danh sách kề
    vector<vector<int>> graph(m);

    // Đánh dấu các đỉnh có thể đến được từ đỉnh 0
    vector<bool> reachable(m, false);

    // Tạo danh sách kề từ danh sách cạnh
    for (int i = 0; i < n; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Thực hiện BFS từ đỉnh 0 để kiểm tra các đỉnh có thể đến được từ đỉnh 0
    bfs(0, graph, reachable);

    // In ra kết quả
    for (int i = 1; i < m; ++i) {
        if (reachable[i])
            cout << "CO" << endl;
        else
            cout << "KHONG" << endl;
    }

    return 0;
}
