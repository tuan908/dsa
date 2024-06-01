/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported sort stable_sort partial_sort partial_sort_copy
sort_heap
set
multi_set
merge
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

int N;

int count_distinct(const vector<string>& ids) {
    map<string, int> Hash;

    // ###INSERT CODE HERE -

    for (const auto& id : ids) {
        Hash[id] = 1;  // Chúng ta chỉ cần lưu mã hàng vào Hash, không cần quan
                       // tâm giá trị
    }

    return Hash.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<string> ids(N);

    for (int i = 0; i < N; i++) cin >> ids[i];

    cout << count_distinct(ids);

    return 0;
}
