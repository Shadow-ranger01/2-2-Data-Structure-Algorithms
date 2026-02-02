#include <iostream>
using namespace std;

#define MAX_SIZE 10   // Maximum size of the stack

// Stack class using array
class Stack {
private:
    int stackArr[MAX_SIZE];  // Array to store stack elements
    int top;                 // Top index ( -1 means empty stack )

public:

    // Constructor initializes stack as empty
    Stack() {top = -1;}

    // Check if stack is empty
    // returns 1 if empty, 0 if not empty
    int isEmpty() const {
        return (top == -1);
    }

    // Check if stack is full
    // returns 1 if full, 0 if not full
    int isFull() const {
        return (top == MAX_SIZE - 1);
    }

    // PUSH operation: adds an element on top of the stack
    void push(int item) {

        // If stack is full, we cannot push
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << item << ".\n";
        } 
        else {
            // Increase top index, then store item
            top++;
            stackArr[top] = item;

            cout << item << " pushed to stack.\n";
        }
    }

    // POP operation: removes the top element and returns it
    int pop() {

        // If stack is empty, nothing to pop
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;  // returning -1 to show error
        } 
        else {
            // Get top element then decrease top index
            int value = stackArr[top];
            top--;

            return value;
        }
    }

    // Peek: returns the top element without removing it
    int peek() const {

        // If stack is empty, no value to show
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        } 
        else {
            return stackArr[top];
        }
    }

    // Display: print whole stack from bottom to top
    void display() const {

        // If empty, no elements to print
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (bottom → top): ";

        for (int i = 0; i <= top; i++) {
            cout << stackArr[i] << " ";
        }

        cout << "\n";
    }
};

int main() {

    Stack s;  // Create a stack object

    // Push values into the stack
    s.push(10);  // stack: 10
    s.push(20);  // stack: 10, 20
    s.push(30);  // stack: 10, 20, 30

    // Show the top value without removing
    cout << "Top element: " << s.peek() << "\n";  // should print 30

    // Pop values (LIFO: last in → first out)
    cout << s.pop() << " popped from stack.\n";   // removes 30
    cout << s.pop() << " popped from stack.\n";   // removes 20

    // Now top value should be 10
    cout << "Top element: " << s.peek() << "\n";

    // Display entire stack
    s.display();

    return 0;
}
