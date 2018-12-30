#include <iostream>

using namespace std;

struct DNode{
    int val;
    DNode* prev;
    DNode* next;
};

DNode* first;
DNode* last;

// Tao node moi
// Make a new node
DNode* makeNode(int v);
// Xoa mot not
void remove(DNode *p);
// Them node vao cuoi day
void insertLast(int x);


int main()
{
    DNode* p;
    p = makeNode(10);
    insertLast(p->val);
    insertLast(11);
    insertLast(12);
    cout << "First value: " << first->val << endl;
    cout << "Last value: " << last->val << endl;
}

DNode* makeNode(int v){
    DNode* p = new DNode;
    p->val = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void remove(DNode* p){
    if(p == NULL) return;
    if(first == last && p == first){
        first = NULL;
        last = NULL;
        delete p;
    }
    if(p == first){
        first = p->next;
        first->prev = NULL;
        delete p;
        return;
    }
    if(p == last){
        last = p->prev;
        last->next = NULL;
        delete p;
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

void insertLast(int x){
    DNode* q = makeNode(x);
    if (first == NULL && last == NULL){
        first = q;
        last = q;
        return;
    }
    q->prev = last;
    last->next = q;
    last = q;
}
