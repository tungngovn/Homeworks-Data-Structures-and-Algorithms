#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

#define INF 10000000
#define MAX 10000

using namespace std;
// using namespace std;

int n,m;
vector<int> A[MAX]; //A[v] list ddinh ke voi v
vector<int> W[MAX]; //W[v] list trong so
int d[MAX];
int p[MAX];
int s;
bool fixed_1[MAX]; // fixed_1[v] = true neu duong di ngan nhat tu s den v da duoc tim thay

void input(char* filename){
    freopen(filename,"r", stdin);
    scanf("%d%d", &n, &m);
    for (int k = 1; k <=m; k++){
        int u,v,wuv;
        scanf("%d%d%d",&u,&v,&wuv);
        A[u].push_back(v);
        A[v].push_back(u);
        W[u].push_back(wuv);
        W[v].push_back(wuv);
    }
}

void printGraph(){
    for (int v = 1; v<=n; v++){
        for(int i = 0; i < A[v].size(); i++){
            int u = A[v][i];
            int wvu = W[v][i];
            printf("(%d%d%d) ", v, u, wvu);
        }
        printf("\n");
    }
}

int findMin(){
    int sel_u = -1;
    int min = INF;
    for (int v = 1; v <=n; v++) if(!(fixed_1[v])){
        if(d[v] < min){
            min = d[v];
            sel_u = v;
        }
    }
    return sel_u;
}

void solve(){
    s = 1;
    for(int v = 1; v <= n; v++){
        d[v] = INF;
        p[v] = s;
        fixed_1[v]=false;
    }
    for(int i = 0; i<A[s].size(); i++){
        int v = A[s][i];
        d[v] = W[s][i];
        cout << "init d[" << v << "] = " << d[v] << endl;
    }
    fixed_1[s] = true;
    d[s] = 0;
    while(true){
        int u = findMin();
        cout << "findMin " << u << " d = " << d[u] << endl;
        if (u == -1) break; // khong tim thay u
        fixed_1[u] = true; //da tim duoc duowng di ngawn nhat tu s toiws u
        for(int i = 0; i<A[u].size();i++){
            int v = A[u][i];
            int wuv = W[u][i];
            if(!fixed_1[v]){
                if(d[v] > d[u] + wuv){
                    d[v] = d[u] +wuv;
                    p[v] = u;
                    cout << "update d[" << v << "] = " << d[v] << endl;
                }
            }
        }
    }
}

void printPath(int v){
    stack<int> S;
    int x = v;
    while( x != s){
        S.push(x);
        x = p[x];
    }
    printf("%d", s);
    while(!S.empty()){
        int x = S.top(); S.pop();
        printf(" -> %d", x);
    }
    printf("\n");
}

void printResult(){
    for(int v = 1; v <=n; v++){
        printf("d[%d] = %d\n", v, d[v]);
    }
}

int main()
{
    input("dijkstra.txt");
    printGraph();
    solve();
    printResult();
    printPath(3);
}

