#include <iostream>
using namespace std;

// Structure for each node
struct Node {
    int data;      // stores the value
    Node* next;    // pointer to the next node
};

// Function prototypes
Node* firstLL(int, Node*);
Node* formLL(int, Node*);
int deleteLast(Node*, int);

int main() {

    int num, data1;
    int c, count;

    // Pointer to head node
    Node* head = nullptr;

    // Pointer to create nodes
    Node* temp1;

    // Pointer for printing
    Node* ptr;

    // Pointer to store last node
    Node* last;

    // Allocate memory for the head node
    head = new Node;
    temp1 = head;

    cout << "Enter number of values: ";
    cin >> num;

    // CASE 1: Only 1 node in linked list
    if (num == 1) {
        cout << "Enter the single element: ";
        cin >> data1;

        head->data = data1;
        head->next = nullptr;

        cout << head->data;
    }

    // CASE 2: Multiple nodes
    else {
        for (int i = 0; i < num; i++) {

            if (i == 0) {
                // Create first node
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = firstLL(data1, temp1);
            }
            else {
                // Create remaining nodes
                cout << "Enter " << i + 1 << " value: ";
                cin >> data1;
                temp1 = formLL(data1, temp1);
            }
        }
    }

    // Print linked list initially
    ptr = head;
    cout << "Linked list is: ";

    for (int i = 0; i < num; i++) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    // Set pointer to last node
    last = ptr;

    // Keep number of nodes
    count = num;

    cout << "\n";

    // -------------------------------
    // Deleting from the last repeatedly
    //-------------------------------
label:
    cout << "Enter 1 to delete the last node: ";
    cin >> c;

    if ((c == 1) && (num != 0)) {

        // Call delete function
        num = deleteLast(head, num);

        if (num > 0) {
            goto label;   // repeat deletion
        }
    }

    // ----------------------------------
    // Print final list when user stops
    // ----------------------------------
    else if (c != 1 && num != 0) {

        Node* temp3 = head;
        cout << "Resultant linked list is: ";

        while (temp3->next != nullptr) {
            cout << temp3->data << " ";
            temp3 = temp3->next;
        }
        cout << temp3->data;
    }

    return 0;
}

// ------------------------------------------
// Create first node of Linked List
// ------------------------------------------
Node* firstLL(int LLData, Node* temp1) {

    temp1->data = LLData;     // store value
    temp1->next = nullptr;    // next empty

    return temp1;
}

// ------------------------------------------
// Create all remaining nodes
// ------------------------------------------
Node* formLL(int LLData, Node* temp1) {

    // Create new node
    Node* temp2 = new Node;

    temp2->data = LLData;     // store value
    temp2->next = nullptr;    // new node ends here

    temp1->next = temp2;      // connect previous node
    temp1 = temp2;            // move pointer to new node

    return temp1;
}

// -------------------------------------------
// Delete LAST node of Linked List
// -------------------------------------------
int deleteLast(Node* delPtr, int num) {

    // If more than 1 node exists
    if (num > 1) {

        // Move pointer to 2nd last node
        for (int i = 0; i < num - 2; i++) {
            delPtr = delPtr->next;
        }

        // temp2 = last node
        Node* temp2 = delPtr->next;

        // Disconnect last node
        delPtr->next = nullptr;

        cout << temp2->data << " is deleted\n";

        // Delete memory
        delete temp2;

        num = num - 1;       // reduce node count
    }

    // If only 1 node remains
    else {
        cout << "Linked list is empty\n";
        num = num - 1;
    }

    return num;
}
