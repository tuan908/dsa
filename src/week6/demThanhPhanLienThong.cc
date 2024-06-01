/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
###End banned keyword*/
// ###INSERT CODE HERE -
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tinhThanhPhanLienThong(int m, int n, vector<vector<int>>& edges) {
    // Danh sach ke
    vector<vector<int>> danhSachKe(m);
    // Danh dau dinh da duoc duyet
    vector<bool> visited(m, false);

    // Tao danh sach ke tu cac canh:
    for (int i = 0; i < n; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];

        danhSachKe[u].push_back(v);
        danhSachKe[v].push_back(u);
    }

    int soThanhPhanLienThong = 0;

    // Duyet tung dinh
    for (int i = 0; i < m; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);  // Bat dau tu i
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                // Duyet cac dinh ke cua u:
                for (int v : danhSachKe[u]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            ++soThanhPhanLienThong;
        }
    }
    return soThanhPhanLienThong;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int soThanhPhanLienThong = tinhThanhPhanLienThong(m, n, edges);
    cout << soThanhPhanLienThong;

    return 0;
}
