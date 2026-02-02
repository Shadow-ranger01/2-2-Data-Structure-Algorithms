//multiple occurence and count number

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
    int count = 0;

    cout << "key " << key << " found at postion ";
    while (current != nullptr)
    {
        if(current->data == key){
            cout << postion << " ";
            count++;
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
    Node* fourth = newNode(70);
    Node* fifth = newNode(50);
    Node* sixth = newNode(60);
    Node* seventh = newNode(70);

    //linking
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;

    cout<< "The link list is: ";
    print_LL(head);

    int key;                                              // searching input structure
    cout<< "Enter the key you want to search : ";
    cin >> key;
    cout<<endl;

    if(search_LL(head, key)){
        cout << "the Key " << key << "found in " << endl ;
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