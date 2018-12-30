#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000
#define MAX_L 256

//Khai bao struct Item
struct Item{
    char* str;
    int count;
    Item* left; //Nut con trai
    Item* right; //Nut con phai
};

Item L[MAX];
int sz;

Item* root;

Item* makeNode(char* s){
    Item* p = new Item;
    p->str = s;
    p->count =1;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Item* find(Item* r, char* s){
    if (r == NULL) return NULL;
    int rs = strcmp(r->str,s);
    if(rs == 0) return r;
    if(rs < 0) return find(r->right,s);
    return find(r->left,s);
}

Item* addNew(Item* r, char* s){
    if(r==NULL) return makeNode(s);
    int rs = strcmp(r->str,s);
    if(rs<0) r->right = addNew(r->right,s);
    else if(rs>0) r->left = addNew(r->left,s);
    return r;
}

void inOrder(Item* r){
    if(r == NULL) return;
    inOrder(r->left);
    printf("%s: %d\n", r->str, r->count);
    inOrder(r->right);
}

void solveB(char* filename){
    freopen(filename,"r",stdin);
    while(!feof(stdin)){
        char* s = new char[MAX_L];
        scanf("%s", s);
        if(strcmp(s,"-1")==0) break;

        //printf("read %s\n", s);

        Item* p = find(root, s);
        if(p != NULL){
            p->count++;
            delete s;
        }else{
            root = addNew(root,s);
        }
    }
}

void BprintResult(){
    printf("----Result----\n");
    inOrder(root);
}

int seqFind(char* s){
    for(int i=0;i<sz;i++){
        if(strcmp(L[i].str,s)==0) return i;
    }
    return -1;
}

void addNew(char* s){
    L[sz].str = s;
    L[sz].count = 1;
    sz++;
}

void printResult(){
    printf("----Result---- \n");
    for (int i = 0; i < sz; i++){
        printf("%s: %d\n", L[i].str, L[i].count);
    }
}

void solve(char* filename){
    freopen(filename,"r",stdin);
    while(!feof(stdin)){
        char* s = new char[MAX_L];
        scanf("%s", s);
        if(strcmp(s,"-1")==0) break;

        printf("read %s\n", s);

        int idx = seqFind(s);
        if(idx >= 0){
            L[idx].count++;
            delete s;
        }else{
            addNew(s);
        }
    }
}

void genText(char* filename, int n, int minL, int maxL){
    FILE* f = fopen(filename,"w");
    char* T = "abcdefxyz";
    for(int i = 0; i < n; i++){
        int L = rand()%((maxL-minL+1)+minL);
        for (int j = 0; j < L; j++){
            int idx = rand()%strlen(T);
            fprintf(f,"%c",T[idx]);
        }
        fprintf(f, " ");
    }
    fprintf(f, "-1");
    fclose(f);
}

int main(){
    genText("words-100000.txt", 90000, 0, 8);
    //solve("words-100000.txt");
    solveB("words-100000.txt");
    printf("%d",sz);
    //printResult();
    BprintResult();
}

