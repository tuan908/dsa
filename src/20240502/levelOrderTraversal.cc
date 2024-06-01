/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include using std
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

    void levelOrder(Node* root) {
        // ###INSERT CODE HERE -
        if (root == nullptr) {
            return;
        }

        // Create a vector to act as a temporary queue
        vector<Node*> queue;
        // Add the root node to the queue
        queue.push_back(root);

        // Iterate until the queue is empty
        while (!queue.empty()) {
            // Get the front node from the queue
            Node* current = queue.front();
            // Print the data of the current node
            cout << current->data << " ";

            // Remove the front node from the queue
            queue.erase(queue.begin());

            // Add the left child of the current node to the queue if it exists
            if (current->left != nullptr) {
                queue.push_back(current->left);
            }
            // Add the right child of the current node to the queue if it exists
            if (current->right != nullptr) {
                queue.push_back(current->right);
            }
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

    myTree.levelOrder(root);

    return 0;
}