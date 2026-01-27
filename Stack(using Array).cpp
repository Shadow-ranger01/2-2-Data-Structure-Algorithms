///5. Stack in cpp {Push, POP}

#include <iostream>   // for std::cout, std::cin
using namespace std;

#define MAX_SIZE 10   // maximum number of elements the stack can hold

// A simple fixed-size stack implemented as a class
class Stack {
private:
    int stackArr[MAX_SIZE]; // array stack
    int top;                // index of the current top element (-1 means empty)

public:
    // Constructor: initialize top to -1 (empty stack)
    Stack() : top(-1) {}

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Push an item onto the stack
    void push(int item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << item << ".\n";
        } else {
            // increment top first, then place item at new top index
            stackArr[++top] = item;
            cout << item << " pushed to stack.\n";
        }
    }

    // Pop the top item from the stack and return it
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1; // sentinel value indicating error (could throw exception instead)
        } else {
            // return stackArr[top] and then decrement top
            return stackArr[top--];
        }
    }

    // Peek at the top item without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // sentinel value for empty stack
        } else {
            return stackArr[top];
        }
    }

    // Optional helper to print the current stack contents (bottom -> top)
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack from bottom to top: ";
        for (int i = 0; i <= top; ++i) {
            cout << stackArr[i] << (i == top ? "" : " ");
        }
        cout << "\n";
    }
};

int main() {
    Stack s;              // create a stack object (initially empty)

    // Push three values onto the stack
    s.push(10);           // top becomes index 0, value 10
    s.push(20);           // top becomes index 1, value 20
    s.push(30);           // top becomes index 2, value 30

    // Show current top element without removing it
    cout << "Top element: " << s.peek() << "\n"; // should print 30

    // Pop two elements (LIFO order)
    cout << s.pop() << " popped from stack.\n"; // removes and prints 30
    cout << s.pop() << " popped from stack.\n"; // removes and prints 20

    // Show top element after pops
    cout << "Top element: " << s.peek() << "\n"; // should print 10

    // Display entire stack content (optional)
    s.display();          // shows remaining element(s)

    return 0;
}
