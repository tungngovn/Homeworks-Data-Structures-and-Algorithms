#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <list>

#define MAX 100

using namespace std;

struct State{
    int x;
    int y;
    State* p; //tro den trang thai sinh ra
    char* action; //mo ta hanh dong de sinh ra trang thai hien tai
};

bool visited[MAX][MAX]; //Danh sach trang thai da xuat hien
int a,b,c;

State* target; //Luu trang thai dich tim den\ sinh ra
queue<State*> Q;
list<State*> L;
State* initState(){
    State* s0 = new State;
    s0->x =0;
    s0->y =0;
    s0->p =NULL;
    s0->action = "";
}

State* makeState(int x, int y, char* action, State* p){
    State* s = new State;
    s->x =x;
    s->y =y;
    s->p =p;
    s->action =action;
    return s;
}

bool checkTarget(State* s){
    return s->x == c || s->y == c || s->x + s->y == c;
}

bool genFill1(State* s){
    // S la trang thai hien tai, sinh ra trang thai tiep theo
    // Neu trang thai tiep theo chua xuat hien thi dua vao Q
    // neu trang thai tiep theo la trang thai dich thi return true
    if (visited[a][s->y]) return false; // Trang thai da ton tai
    State* ns = makeState(a,s->y,"Do day nuoc vao coc 1",s);
    Q.push(ns);
    L.push_back(ns);
    visited[a][s->y] = true;
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;

}

bool genFill2(State* s){
    if (visited[s->x][b]) return false;
    State* ns = makeState(s->x,b,"Do day nuoc vao coc 2",s);
    Q.push(ns);
    L.push_back(ns);
    visited[s->x][b] = true;
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;
}

bool genEmpty1(State* s){
    if (visited[0][s->y]) return false;
    State* ns = makeState(0,s->y,"Do het nuoc coc 1",s);
    Q.push(ns);
    L.push_back(ns);
    visited[0][s->y] = true;
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;
}

bool genEmpty2(State* s){
    if (visited[s->x][0]) return false;
    State* ns = makeState(0,s->y,"Do het nuoc coc 2",s);
    Q.push(ns);
    L.push_back(ns);
    visited[s->x][0] = true;
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;
}

bool genMove1to2(State* s){
    State* ns = NULL;
    if(s->x + s->y >=b ){
        if(visited[s->x + s->y - b][b]) return false;
        ns = makeState(s->x + s->y - b, b, "Do nuoc tu coc 1 sang coc 2",s);
        visited[s->x + s->y - b][b] = true;
    }else{
        if(visited[0][s->x + s->y]) return false;
        ns = makeState(0,s->x + s->y,"Do nuoc tu coc 1 sang coc 2",s);
        visited[0][s->x + s->y] = true;
    }
    Q.push(ns);
    L.push_back(ns);
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;
}

bool genMove2to1(State* s){
    State* ns = NULL;
    if(s->x + s->y >=a ){
        if(visited[a][s->x+s->y-a]) return false;
        ns = makeState(a,s->x + s->y - a, "Do nuoc tu coc 2 sang coc 1",s);
        visited[a][s->x + s->y - a] = true;
    }else{
        if(visited[s->x + s->y][0]) return false;
        ns = makeState(s->x + s->y,0,"Do nuoc tu coc 2 sang coc 1",s);
        visited[s->x + s->y][0] = true;
    }
    Q.push(ns);
    L.push_back(ns);
    bool ok = checkTarget(ns);
    if(ok){
        target = ns;
        return true;
    }
    else return false;
}

void solve(){

    State* s0 = initState();
    target = NULL;
    Q.push(s0);
    while(!Q.empty()){
        State* s = Q.front();
        Q.pop();
        if(genFill1(s)) break;
        if(genFill2(s)) break;
        if(genEmpty1(s)) break;
        if(genEmpty2(s)) break;
        if(genMove1to2(s)) break;
        if(genMove2to1(s)) break;

    }
    if (target == NULL) cout << "Not found" << endl;
    else{
        stack<State*> S;
        State* x = target;
        while(x!= s0){
            S.push(x);
            x = x->p;
        }
        cout << "(" << s0->x << "," << s0->y << ")" << endl;
        while(!S.empty()){
            State* s= S.top();
            S.pop();
            cout << "(" << s->x << "," << s->y << ")" << s->action << endl;
        }
        for(list<State*>::iterator it = L.begin(); it!= L.end();it++){
            delete *it;
        }
    }
}

int main(){
    a=2;
    b=2;
    c=3;
    solve();
}
