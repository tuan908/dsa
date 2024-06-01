/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include using std inOrder
###End banned keyword*/

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

    void inOrder(Node* root) {
        // ###INSERT CODE HERE -
        if (root == nullptr) {
            return;
        }

        // Create a vector to act as a stack
        vector<Node*> stack;
        Node* current = root;

        // Traverse the tree
        while (current != nullptr || !stack.empty()) {
            // Traverse to the leftmost node of the current subtree
            while (current != nullptr) {
                stack.push_back(current);
                current = current->left;
            }

            // Pop the top node from the stack
            current = stack.back();
            stack.pop_back();

            // Print the value of the current node
            cout << current->data << " ";

            // Move to the right child
            current = current->right;
        }
    }

};  // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.inOrder(root);

    return 0;
}