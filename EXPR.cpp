#include <iostream>

using namespace std;
int n;
int a[30];
int b;
int p;
int dem;

void TRY(int k);

int main()
{
    cin >> n >> b;
    for (int i=0;i<n;i++) cin >> a[i];
    p=a[0];
    TRY(1);
    cout << dem;
}

void TRY(int k){
    if (k==n){
        if (p==b) dem++;
    }
    else{
        for (int v=-1;v<=1;v=v+2){
            p = p + v*a[k];
            TRY(k+1);
            p = p - v*a[k];
        }
    }
}
