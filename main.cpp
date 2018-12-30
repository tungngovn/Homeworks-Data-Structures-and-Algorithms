#include <iostream>

using namespace std;

struct Node{
    int id;
    Node* Left;
    Node* Right;
};

Node* find(Node* r, int v){
    //Tim va tra ve con tro tro den nut co id bang v tren cay goc la r
    if (r == NULL) return NULL;
    if (r->id == v) return r;
    Node* p = r->Left;
    while(p != NULL){
        Node* q = find(p,v);
        if(q!= NULL) return q;
        p = p->Right;
    }
    return NULL;
}

Node* makeNode(int v){
    Node* p = new Node;
    p->id = v;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

Node* insertLastChild(Node* r, Node* p, int v){
    //Tao ra 1 nut co dinh danh la v, chen vao cuoi danh sach nut con cua p tra ve con tro tro den nut goc cua cay thu duoc
    if(r == NULL) return NULL;
    if(p == NULL) return NULL;
    Node* q = makeNode(v);
    Node* h = p->Left;
    if(h == NULL) p->Left = q; //
    else{
        while (h->Right != NULL) h= h->Right;
        h->Right = q;
    }
    return r;
}

Node* insertLastChildID(Node* r, int u, int v){
    Node* p = find(r,u);
    return insertLastChild(r,p,v);
}

void printTree(Node* r){
    if (r == NULL) return;
    Node* p = r->Left;
    cout << endl << r->id << ": ";
    while(p!=NULL){
        cout << p->id << " ";
        p=p->Right;
    }
    cout << endl;
    p = r->Left;
    while(p!=NULL){
        printTree(p);
        p = p->Right;
    }
}

int count(Node* r){
    int c;
    if (r==NULL) return;
    Node* p = r->Left;
    if (p !=NULL) c++;
    if (r->Right !=NULL) c++;
}
*/

int count(Node* r){
    if(r == NULL) return 0;
    int c = 1;
    Node* p = r->Left;
    while(p!= NULL){
        c += count(p);
        p = p->Right;
    }
    return c;
}

int countLeaves(Node* r){
    if(r == NULL) return 0;
    int c = 0;
    Node* p = r->Left;
    if (p == NULL) c = 1;
    while(p!=NULL){
        c+= countLeaves(p);
        p = p->Right;
    }
    return c;
}

int height(Node* r, int v){

}

Node* parent(Node* r, int v){
    Node* p = find(r,v);
    if (r == NULL) return NULL;
    Node* q = r->Left;
    while(q != NULL){
        if (p == q) return r;
        Node* pp = parent(q, p->id);
        if(pp != NULL) return pp;
        q = q->Right;
    }
    return NULL;
}

void preOrder(Node* r){

}

void inOrder(Node* r){

}

void postOrder(Node* r){

}

int main()
{
    Node* root = makeNode(10);
    root = insertLastChildID(root,10,11);
    root = insertLastChildID(root,10,1);
    root = insertLastChildID(root,10,3);

    root = insertLastChildID(root,11,5);
    root = insertLastChildID(root,11,4);

    root = insertLastChildID(root,3,8);
    root = insertLastChildID(root,3,2);
    root = insertLastChildID(root,3,7);

    root = insertLastChildID(root,4,6);
    root = insertLastChildID(root,4,9);
    printTree(root);

    cout << "so nut" << count(root) << endl;
    cout << "The number of leaves is: " << countLeaves(root) <<endl;
    cout << "Parent: " << parent(root,6)->id <<endl;
}

