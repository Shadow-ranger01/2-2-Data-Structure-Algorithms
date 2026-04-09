#include <bits/stdc++.h>
using namespace std;

struct item {
    char ch;
    int f;
    item *left;
    item *right;

    item(char character, int frequency) {
        ch = character;
        f = frequency;
        left = right = NULL;
    }
};

// (min heap)
struct compare {
    bool operator()(item* left, item* right) {
        return left->f > right->f;
    }
};

// Function to print Huffman Codes
void huffman_code(item* root, string str) {
    if (!root) return;

    // Leaf node = actual character
    if (root->left == NULL && root->right == NULL) {
        cout << "Character: " << root->ch 
             << "  | Huffman Code: " << str << endl;
    }

    huffman_code(root->l, str + "0");
    huffman_code(root->r, str + "1");
}

int main() {
    int n;

    cout << "================ HUFFMAN CODING PROGRAM ================\n";
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<item*, vector<item*>, compare> q;

    cout << "\nEnter character and its frequency:\n";
    cout << "(Example: a 5)\n\n";

    for (int i = 0; i < n; i++) {
        char ch;
        int f;
        cout << "Enter character " << i+1 << " and frequency: ";
        cin >> ch >> f;

        q.push(new item(ch, f));
    }

    cout << "\n--- Building Huffman Tree ---\n";

    // Build Huffman Tree
    while (q.size() > 1) {
        item *i1 = q.top(); q.pop();
        item *i2 = q.top(); q.pop();

        cout << "Combining nodes: (" << i1->ch << "," << i1->f << ") + ("
             << i2->ch << "," << i2->f << ")";

        item *i3 = new item('$', i1->f + i2->f);
        i3->l = i1;
        i3->r = i2;

        cout << " --> New node frequency: " << i3->f << endl;

        q.push(i3);
    }

    cout << "\n--- Huffman Codes Generated ---\n\n";

    huffman_code(q.top(), "");

    cout << "\n========================================================\n";
    cout << "Huffman Coding Completed Successfully!\n";

    return 0;
}
