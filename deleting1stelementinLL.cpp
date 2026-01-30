///9. Deleting of 1st element of an LL

#include <iostream>
using namespace std;

// -------------------------
// Structure for each node
// -------------------------
struct Node {
    int data;       // stores value
    Node* next;     // pointer to the next node
};

// Function prototypes
Node* firstLL(int, Node*);
Node* formLL(int, Node*);
Node* deleteFront(Node*);

int main() {

    int num, data1;
    int choice;

    // Pointer to head node (start of linked list)
    Node* head = nullptr;

    // Pointer used for creating nodes
    Node* temp1;

    // Pointer used for printing
    Node* ptr;

    // Allocating memory for the first node
    head = new Node;
    temp1 = head;

    cout << "Enter number of values: ";
    cin >> num;

    // -----------------------------
    // CASE: Only 1 value in the list
    // -----------------------------
    if (num == 1) {
        cout << "Enter the single element: ";
        cin >> data1;

        head->data = data1;
        head->next = nullptr;

        cout << head->data;
    }

    // --------------------------------
    // CASE: More than 1 value in list
    // --------------------------------
    else {
        for (int i = 0; i < num; i++) {

            // First node creation
            if (i == 0) {
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = firstLL(data1, temp1); // creates first node
            }

            // Remaining nodes creation
            else {
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = formLL(data1, temp1);  // adds node after first
            }
        }
    }

    // -----------------------------
    // Printing initial linked list
    // -----------------------------
    cout << "Linked list is: ";
    ptr = head;
    for (int i = 0; i < num; i++) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";

    // -----------------------------
    // Repeated deletion from front
    // -----------------------------
label:
    cout << "Enter 1 to delete a node from the front: ";
    cin >> choice;

    if (choice == 1) {

        // Showing the value being deleted
        cout << head->data << " is deleted\n";

        // Delete first node
        head = deleteFront(head);

        // Repeat (GOTO)
        goto label;
    }

    // -----------------------------
    // Printing final resultant list
    // -----------------------------
    else {
        cout << "Resultant linked list is: ";

        Node* temp3 = head;
        while (temp3->next != nullptr) {
            cout << temp3->data << " ";
            temp3 = temp3->next;
        }
        cout << temp3->data;
    }

    return 0;
}

// ---------------------------------------------------
// Creates the VERY FIRST node in the linked list
// ---------------------------------------------------
Node* firstLL(int LLData, Node* temp1) {
    temp1->data = LLData;       // Store value
    temp1->next = nullptr;      // Next is empty
    return temp1;               // Return pointer to the node
}

// ---------------------------------------------------
// Creates all other nodes AFTER the first one
// ---------------------------------------------------
Node* formLL(int LLData, Node* temp1) {

    // Create a new node dynamically
    Node* temp2 = new Node;

    temp2->data = LLData;       // Store value
    temp2->next = nullptr;      // End of list for now

    temp1->next = temp2;        // Attach new node to the current list
    temp1 = temp2;              // Move temp1 to new node

    return temp1;
}

// ---------------------------------------------------
// Delete FIRST node (front deletion)
// ---------------------------------------------------
Node* deleteFront(Node* head) {

    Node* temp2 = head;    // Store current head
    head = head->next;     // Move head to next node
    delete temp2;          // Free old head memory

    return head;           // Return new head
}
