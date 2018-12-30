#include <stdio.h>
#include <string.h>
#include <iostream>

struct Node{
    char c;
    Node* next;
};

Node* top;

void push (char a){
    Node* n = new Node;
    n->c = a; n->next = top;
    top = n;
}

char pop(){
    Node* tmp = top;
    top = top->next;
    char a = tmp->c;
    delete tmp;
    return a;
}

bool empty(){
    return top == NULL;
}

void reset(){
    top = NULL;
}

bool match(char o, char c){
    if(o=='{' && c == '}') return true;
    if(o=='[' && c == ']') return true;
    if(o=='(' && c == ')') return true;
    return false;
}

bool solve(char* s){
    reset();
    for (int i = 0; i< strlen(s); i++){
        char a = s[i];
        if (a== '[' || a == '{' || a == '('){
            push(a);
        }else{
            if(empty()) return false;
            char b = pop();
            if (!match(b,a)) return false;
        }
    }
    return empty();
}


int main(){
    char* s = "{{[]";
    bool ck = solve(s);
    std::cout << ck;
}
