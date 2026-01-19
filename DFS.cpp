#include <iostream>
#include <cstdlib>

using namespace std;

// Node structure for adjacency list
struct Node {
    int data;           // stores vertex number
    Node* next;         // pointer to next node
};

// Adjacency list structure
struct AdjList {
    Node* head;         // head of linked list
};

// Global variables
int q[20], top = -1, front = -1, rear = -1;
int vis[20], stack[20];
AdjList adjList[20];
int a[20][20];          // adjacency matrix

// Function declarations
int delete_q();
void add(int item);
void dfs_matrix(int s, int n);
void dfs_list(int s, int n);
void push(int item);
int pop();
void printAdjList(int n);

int main() {
    int n, i, s, ch, j;
    char c;

    cout << "Enter the no. of vertices : ";
    cin >> n;

    // Input adjacency matrix and build adjacency list
    for (i = 1; i <= n; i++) {
        adjList[i].head = NULL;
        for (j = 1; j <= n; j++) {
            cout << "ENTER 1 IF " << i << " HAS A NODE WITH " << j << " ELSE 0 : ";
            cin >> a[i][j];

            // If edge exists, add to adjacency list
            if (a[i][j] == 1) {
                Node* newNode = new Node;
                newNode->data = j;
                newNode->next = adjList[i].head;
                adjList[i].head = newNode;
            }
        }
    }

    // Display adjacency matrix
    cout << "\nTHE ADJACENCY MATRIX IS : \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }

    // Display adjacency list
    cout << "\nTHE ADJACENCY LIST IS : \n";
    printAdjList(n);

    do {
        // Reset visited array
        for (i = 1; i <= n; i++)
            vis[i] = 0;

        cout << "\nMENU";
        cout << "\n1.D.F.S (Adjacency Matrix)";
        cout << "\n2.D.F.S (Adjacency List)";
        cout << "\nEnter your choice: ";
        cin >> ch;

        cout << "Enter the start vertex : ";
        cin >> s;

        switch (ch) {
            case 1:
                cout << "\nDFS using Adjacency Matrix:\n";
                dfs_matrix(s, n);
                break;
            case 2:
                cout << "\nDFS using Adjacency List:\n";
                dfs_list(s, n);
                break;
        }

        cout << "\nDO U WANT TO CONTINUE(Y/N) ?: ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}

// DFS using adjacency matrix
void dfs_matrix(int s, int n) {
    int i, k;

    push(s);
    vis[s] = 1;

    k = pop();
    if (k != 0)
        cout << " " << k;

    while (k != 0) {
        for (i = 1; i <= n; i++) {
            if (a[k][i] != 0 && vis[i] == 0) {
                push(i);
                vis[i] = 1;
            }
        }
        k = pop();
        if (k != 0)
            cout << " " << k;
    }

    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs_matrix(i, n);
}

// DFS using adjacency list
void dfs_list(int s, int n) {
    int i, k;

    push(s);
    vis[s] = 1;

    k = pop();
    if (k != 0)
        cout << " " << k;

    while (k != 0) {
        Node* current = adjList[k].head;

        while (current != NULL) {
            if (vis[current->data] == 0) {
                push(current->data);
                vis[current->data] = 1;
            }
            current = current->next;
        }

        k = pop();
        if (k != 0)
            cout << " " << k;
    }

    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs_list(i, n);
}

// Queue insert
void add(int item) {
    if (rear == 19)
        cout << "QUEUE FULL";
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else
            q[++rear] = item;
    }
}

// Queue delete
int delete_q() {
    if (front > rear || front == -1)
        return 0;
    else
        return q[front++];
}

// Stack push
void push(int item) {
    if (top == 19)
        cout << "Stack overflow ";
    else
        stack[++top] = item;
}

// Stack pop
int pop() {
    if (top == -1)
        return 0;
    else
        return stack[top--];
}

// Print adjacency list
void printAdjList(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ": ";
        Node* current = adjList[i].head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
}
