#include <iostream>

using namespace std;

class Node{

    friend class LinkedList;

    private:
    int data;
    Node *next;

    public:
    Node(int val){
        data = val;
    }


    

};

class LinkedList{

    private:
    Node *head;

    public:
    LinkedList(){
        head = NULL;

    }

    //insert at end
    void insert_end(Node *newNode){

        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //insert at start
    void insert_start(Node *newNode){
        newNode->next = head;
        head = newNode;
    }   

    //Delete from beginning
    void delete_start(){
        head = head->next;
    }

    //Delete from end
    void delete_end(){
        Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void print_linkedlist(){
        Node *temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};


int main(){

    Node *node1 = new Node(12);
    Node *node2 = new Node(13);
    Node *node3 = new Node(14);
    Node *node4 = new Node(15);
    Node *node5 = new Node(16);
    Node *node6 = new Node(17);


    LinkedList *linkedlist = new LinkedList();

    linkedlist->insert_start(node1);
    linkedlist->insert_start(node2);
    linkedlist->insert_start(node3);
    linkedlist->insert_start(node4);

    linkedlist->print_linkedlist();

    cout<<"Delete beginning"<<endl;
    linkedlist->delete_start();
    linkedlist->print_linkedlist();

    cout<<"Delete last"<<endl;
    linkedlist->delete_end();
    linkedlist->print_linkedlist();




    // Node *node1 = NULL;
    // Node *node2 = NULL;
    // Node *node3 = NULL;

    // node1 = new Node();
    // node2 = new Node();
    // node3 = new Node();

    // node1->data = 3;
    // node1->next = node2;

    // node2->data = 2;
    // node2->next = node3;

    // node3->data = 4;
    // node3->next = NULL;




    return 0;
}