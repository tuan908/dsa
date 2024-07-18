#include <iostream>
#include <string>

using namespace std;

struct Date {
    int ngay, thang, nam;
};

struct Node {
    string fullName;
    Date birthday;
    Node* next;
};

void init(Node* node) {
    node->next = nullptr;
}

void create() {}

void print(Node* tree) {
    while (tree->next != nullptr) {
        cout << tree->fullName << " " << tree->birthday.nam << "-"
             << tree->birthday.thang << "-" << tree->birthday.ngay;
        tree = tree->next;
    }
}

int main() {
    Node* tree;

    init(tree);
    print(tree);

    return 0;
}