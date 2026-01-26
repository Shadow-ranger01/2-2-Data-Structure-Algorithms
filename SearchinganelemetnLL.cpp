// 1. Search for an element by value (linear search).

#include<iostream>
using namespace std;

class Node{
public:
    int data;           // data 
    Node* next;         // next node pointer

    Node(int x){
        data = x;       //exact data of the node
        next = NULL;    //initial link will be NULL
    }

};

int search_Element (Node* head ,int key)
{
    Node* current = head;     // putting data of head into current 
    int position = 1;         // initial postion 

    while(current != NULL){           // Loop will run until the end (Bec end is NULL)
        if(current->data == key){     // if data == key the the postiton will return 
            return position;
        }
        current = current->next;     //  current will move to the next node
        position++;                  //  incrementing the position 
    } 

    return 0;                        // if not found
}

int main(){

    //link list 1->3->3->3->5 
    Node* head = new Node(1);
    head -> next = new Node(3);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next = new Node(5);

    int key;
    cout << "Enter The key/data you want to search : ";
    cin >> key;
    cout << endl;

    int result = search_Element(head, key);

    if(result == 0){
        cout << "Element " << key <<" not found in the Linked List" << endl;
    }
    else{
        cout << "Element " << key << " found at positon "<< result << endl;
    }

    return 0;
}
