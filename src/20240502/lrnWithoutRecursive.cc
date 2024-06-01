
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void postOrder(Node* root) {
        vector<Node*> visited;

        Node* current = root;
        Node* lastVisited = nullptr;

        while (current || !visited.empty()) {
            if (current) {
                visited.push_back(current);
                current = current->left;
            } else {
                Node* temp = visited.back();

                if (temp->right == nullptr || temp->right == lastVisited) {
                    cout << temp->data << " ";
                    visited.pop_back();
                    lastVisited = temp;
                } else {
                    current = temp->right;
                }
            }
        }
    }

};  // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);

    return 0;
}