/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include using std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
   public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// ###INSERT CODE HERE -

void insert_node(SinglyLinkedList *l, int x) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(x);
    newNode->next = l->head;
    l->head = newNode;
}

void reverseLinkedList(SinglyLinkedList *l) {
    SinglyLinkedListNode *current = l->tail;
    SinglyLinkedListNode *prev = l->head;

    while (current != nullptr) {
        SinglyLinkedListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    l->head = prev;
}

void printLinkedList(SinglyLinkedList *l) {
    SinglyLinkedListNode *current = l->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    SinglyLinkedList *llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
