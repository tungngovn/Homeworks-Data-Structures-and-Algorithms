#include <iostream>

#define MAX 100000

int a[MAX];
int s[MAX];

using namespace std;

int max(int a, int b);

int main()
{
    int n;
    int L1,L2;
    cin >> n >> L1 >> L2;
    for (int i=0; i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++){
        if ((i-L1)<0) s[i]=a[i];
        else{
            s[i] = a[i] + max(i-L2,i-L1);
        }
    }
    cout << max(0,n);
}

int max(int a, int b){
    int m = 0;
    if (a<0) a=0;
    for (int j=a;j<=b;j++){
        if (s[j]>m) m=s[j];
    }
    return m;
}
