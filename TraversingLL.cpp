///7. Traversing of LL

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function prototypes
Node* firstLL(int, Node*);
Node* formLL(int, Node*);

int main() {
    int num, data1;

    Node* head = nullptr;   // starting node of the list
    Node* temp1 = nullptr;  // used for creating nodes
    Node* ptr = nullptr;    // used for printing

    // Allocate the first node
    head = new Node;
    temp1 = head;

    cout << "Enter number of values: ";
    cin >> num;

    if (num == 1) {
        cout << "Enter the single element: ";
        cin >> data1;
        head->data = data1;
        head->next = nullptr;

        cout << head->data;
    } 
    else {
        for (int i = 0; i < num; i++) {

            if (i == 0) {
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = firstLL(data1, temp1);
            } 
            else {
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = formLL(data1, temp1);
            }
        }
    }

    // Print the entire linked list
    cout << "\nLinked List: ";
    temp1 = head;
    for (int i = 0; i < num; i++) {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    return 0;
}

// Function to initialize the first node
Node* firstLL(int LLData, Node* temp1) {
    temp1->data = LLData;
    temp1->next = nullptr;
    return temp1;
}

// Function to form the rest of the linked list
Node* formLL(int LLData, Node* temp1) {
    Node* temp2 = new Node;
    temp2->data = LLData;
    temp2->next = nullptr;

    temp1->next = temp2; // link previous node to new node
    temp1 = temp2;       // move temp1 to new node

    return temp1;
}
