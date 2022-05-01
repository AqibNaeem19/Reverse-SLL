#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        // Constructor
        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    // If there's no node in list
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void searchLinkedList(node* head, int key){
    node* temp = head;
    int index = 0;
    while(temp != NULL){
        if(temp->data == key){
            cout<< "Key Found At Index : "<< index << endl;
            return;
        }
        index++;
        temp = temp->next;
    }
    cout << "Key is not present in the list "<< endl;
    return;
}

void deleteNode(node* &head, int val){
    // If the list is empty
    if(head == NULL){
        return;
    }
    // Deleting the first node in list
    if(head->data == val){
        node* delNode = head;
        head = head -> next;
        delete delNode;
        return;
    }
    // If there's only one element in list
    if(head -> next == NULL){
        delete head;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp->next->data != val){
        temp = temp -> next;
    }
    node* delNode = temp -> next;
    temp-> next = temp->next->next;
    delete delNode;
}

void printLinkedList(node* head){
    // If list is empty
    if(head == NULL){
        cout<< "Nothing to print in the list "<< endl;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp != NULL){
        cout<< temp->data<< " "<<temp->next<< endl;
        temp = temp->next;
    }
}

node* reverse(node* &head){
  // Reverse using 3 pointers
  node* previousPointer = NULL;
  node* currentPointer = head;
  node* nextPointer;

  while( currentPointer != NULL){
    // Reversing the pointers
    nextPointer = currentPointer -> next;
    currentPointer -> next = previousPointer;

    // Moving the pointers to next node
    previousPointer = currentPointer;
    currentPointer = nextPointer;
  }
  head = previousPointer;
  return previousPointer;
}

void destroyList(node* &head){
  if(head == NULL) {
    return;
  }
  
  while(head != NULL){
    node* nextNode = head -> next;
    delete head;
    head = nextNode;
  }
}

int main(){
    node* head = NULL;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    printLinkedList(head);

    // Reverse the list
    reverse(head);
    printLinkedList(head);
    
    // Free the memory allocation
    destroy(head);
    printLinkedList(head);
    return 1;
}