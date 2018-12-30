#include <iostream>

using namespace std;

// Tao kieu du lieu node
struct Node{
    int id;
    Node* Left;
    Node* Right;
};

// Tim va tra ve con tro tro den nut co id bang v tren cay co goc la r
Node* find(Node* r, int v){
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

// Tao node co gia tri v
Node* makeNode(int v){
    Node* p = new Node;
    p->id = v;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

// Chen nut co id = v vao cuoi danh sach nut con cua node p, tra ve con tro tro den goc cua cay
Node* insertLastChild(Node* r, Node* p, int v){
    if(r == NULL) return NULL;
    if(p == NULL) return NULL;
    Node* q = makeNode(v);
    Node* h = p->Left;
    if(h == NULL) p->Left = q;
    else{
        while (h->Right != NULL) h= h->Right;
        h->Right = q;
    }
    return r;
}
// Chen nut co id = v vao cuoi danh sach nut con cua node co id = u, tra ve con tro tro den goc cua cay
Node* insertLastChildID(Node* r, int u, int v){
    Node* p = find(r,u);
    return insertLastChild(r,p,v);
}

// In cay ra man hinh
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

// Dem so node trong cay
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

// Dem so la cua cay
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

// Tinh chieu cao cua cay
int height(Node* r, int v){

}

// Tim node cha cua node r
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

// Duyet theo thu tu truoc
void preOrder(Node* r){
    if(r == NULL) return;
    cout << r->id;
    Node* p = r->Left;
    while(p!=NULL){
        preOrder(p);
        p = p->Right;
    }
}

// Duyet theo thu tu giua
void inOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->Left;
    inOrder(p);
    cout << r->id;
    if(p != NULL) p = p->Right;
    while(p != NULL){
        inOrder(p);
        p = p->Right;
    }
}

// Duyet theo thu tu sau
void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->Left;
    while(p!=NULL){
        postOrder(p);
        p = p->Right;
    }
    cout << r->id;
}

// Ham main
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

    //cout << "so nut" << count(root) << endl;
    //cout << "The number of leaves is: " << countLeaves(root) <<endl;
    //cout << "Parent: " << parent(root,6)->id <<endl;
}
