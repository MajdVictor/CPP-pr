#include <iostream>

using namespace std;

class Node{

    public:
    int data;
    Node *next;

    

};

void printList(Node* node){
        while(node != NULL){
            cout<<node->data<<endl;
            node = node->next;
        }
    }

int main(){

    Node *node1 = NULL;
    Node *node2 = NULL;
    Node *node3 = NULL;

    node1 = new Node();
    node2 = new Node();
    node3 = new Node();

    node1->data = 3;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 4;
    node3->next = NULL;

    printList(node1);


    return 0;
}