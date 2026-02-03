//link list inputed manually in runtime

#include<iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

Node* newNode(int value){

     Node* temp = new Node;
     
     temp->data = value;
     temp->next = nullptr;

     return temp;

}

void printLL(Node* head){
    
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
  cout<< "Null\n";

}

int main(){

    Node* head = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30);

    //linking
    head -> next = second;
    second -> next = third;

    cout<< "The link list: ";
    printLL(head);

    delete head;
    delete second;
    delete third;

    return 0; 
}