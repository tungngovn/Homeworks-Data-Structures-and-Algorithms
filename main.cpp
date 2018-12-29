#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* head;

// Nhap day cac node
// Input nodes
void input();
// In danh sach cac node tu do cao "h" ve cuoi
void printList(Node* h);
// Tim node cuoi ke tu not co do cao "h"
// Find the last node from the node with h of height
Node* findLast(Node* h);
// Tao node co gia tri x
// Find the node whose value is x
Node* makeNode(int x);
// Them mot node gia tri x vao sau node p (head node la h)
// Add a node with value x in after the node with position p
Node* insertAfter(Node* h, Node* p, int x);
// Them mot node vao cuoi day
// Add a node to the end
Node* insertLast(Node* h, int x);
// Tim vi tri nut co gia tri x
// Find the position of the node which has value x
Node* locate(Node* h, int x);
// Tim node lien truoc
// Return the previous node
Node* prev(Node* h, Node* p);


// Ham main
// Main function
int main()
{
    int a;
    cout << "Input the value of head node: ";
    cin >> a;
    head = makeNode(a);
    input();
    printList(head);
    // Node* p;
    // insertAfter(head, 3, 6);
    // printList(head);
    locate(head, 3);
    // prev(head, 3);
    // printList(head);


    return 0;
}

void input(){
    int v;
    while(v>=0){
        cout << endl << "Input the next value: ";
        cin >> v;
        if (v>=0) insertLast(head, v);
    }
}

void printList(Node *h){
    Node* p = h;
    while (p!=NULL){
        cout << endl << p->value;
        p = p->next;
    }
}

Node* findLast(Node* h){
    Node* p = h;
    while(p!=NULL){
        if (p->next == NULL) return p;
        p = p->next;
    }
    return NULL;
}

Node* makeNode(int x){
    Node* q = new Node;
    q->value = x;
    q->next = NULL;
    return q;
}

Node* insertAfter(Node *h, Node *p, int x){
    Node* q = makeNode(x);
    if (h==NULL) return q;
    if (p==NULL){
        h->next = q;
    }
    q->next = p->next;
    p->next = q;
    return q;
}

Node* insertLast(Node *h, int x){
    Node* q = makeNode(x);
    if (h==NULL) return q;
    Node* Last = findLast(h);
    Last->next = q;
    return q;
}

Node* locate(Node *h, int x){
    Node* p = h;
    while(p != NULL){
        if(p->value==x) return p;
        p = p->next;
    }
    return NULL;
}

Node* prev(Node *h, Node *p){
    Node* q = h;
    while(q!=NULL){
        if (q->next==p) return q;
        q = q->next;
    }
    return NULL;
}

