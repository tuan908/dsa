#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    if(s.length() < 2) {
        cout << "Invalid";
        return 0;
    }

    cout << s;

    return 0;
}