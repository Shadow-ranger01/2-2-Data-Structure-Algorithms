// serching a linklist linearly 

#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;
};

Node* newNode(int value){

    Node* temp = new Node;

    temp -> data = value;
    temp -> next = nullptr;

    return temp;
}

int search_LL(Node* head, int key){
      
    Node* current = head;
    int postion = 1;

    while (current != nullptr)
    {
        if(current->data == key){
              return postion;
        }
        current = current->next;
        postion++;
    }
    
   return 0; 
}

void print_LL(Node* head){
     Node* current = head;

     while (current != nullptr)
     {
        cout << current->data << "->";
        current = current -> next;
     }
     
     cout << " NULL\n ";
}

int main(){
    
    Node* head = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30);
    Node* fourth = newNode(40);
    Node* fifth = newNode(50);

    //linking
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;

    cout<< "The link list is: ";
    print_LL(head);

    int key;                                              // searching input structure
    cout<< "Enter the key you want to search : ";
    cin >> key;
    cout<<endl;

    if(search_LL(head, key)){
        cout << "the Key found " << key << " in " << search_LL(head,key) << "th position."  ;
    }
    else{
        cout << "the key not found in the link list";
    }                                                   // searching structure end in the main function

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}