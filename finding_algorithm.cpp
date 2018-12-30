#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* find(Node* r, int k){
    Node* p;
    if (r==NULL) return NULL;
    int key = r->key;
    if(k == key) return r;
    else if(k<key){
        p = r->left;
        return find(p,k);
    }
    else if (k>key) {
        p = r->right;
        return find(p,k);
    }
}

Node* insert(Node* r, int k);

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

Node* insert(Node* r, int k){
    Node* p;
    if (r==NULL) return NULL;
    int key = r->key;
    if(k == key) return NULL;
    if(k<key){
        p = r->left;
    }
    else if (k>key) {
        p = r->right;
    }
    if (p==NULL) {
        p->key = k;
        return p;
    }
    else return insert(p,k);
}
