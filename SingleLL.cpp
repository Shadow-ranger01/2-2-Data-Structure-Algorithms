///6. traversing of a single link list

#include <iostream>
using namespace std;

// Create a structure (class-like) for a Node in Linked List
struct Node {
    int data;      // stores value
    Node* next;    // pointer to the next node
};

// Function to create a new node and return its pointer
Node* createNode(int value) {
    // Dynamically create memory for a new node
    Node* newNode = new Node;

    // Store data inside the node
    newNode->data = value;
    newNode->next = nullptr;  // next initially empty

    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;  // start from the head

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;  // move to next node
    }
    cout << "NULL\n";
}

int main() {

    // Create nodes and store values
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    // Connect the nodes (linking)
    head->next = second;
    second->next = third;

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Free the memory using delete (C++ version of free())
    delete head;
    delete second;
    delete third;

    return 0;
}
