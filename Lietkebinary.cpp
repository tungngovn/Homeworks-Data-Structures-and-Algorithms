#include <iostream>

using namespace std;

void printSo(int x[], int n){
    for (int k=0; k<n; k++)
        cout << x[k];
    cout << endl;
}

int TRY(int x[], int n, int k){
    for (int v = 0; v<=1; v++){
        x[k] = v;
        if(k == n-1) printSo(x,n);
        else TRY(x, n, k+1);
    }
    return 1;
}

int TRYM(int x[], int n, int k){
    for (int v = 0; v<=1; v++){
        if (x[k-1]+v < 2){
            x[k] = v;
            if (k == n-1) printSo(x, n);
            else TRYM(x,n,k+1);
        }
    }
    return 1;
}

int main()
{
    int x[10];
   // int n=4;
    //TRY(x,4,0);
    TRYM(x,4,0);
    return 0;
}

