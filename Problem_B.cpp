#include <iostream>

using namespace std;

#define MAX 100000000

int n;
int a[MAX];

int s[MAX];
int mx = 0;

int main(){
    cin >> n;
    int i;
    for (i=0;i<n;i++) cin >> a[i];

    s[0] = a[0];
    for (i=1;i<n;i++){
        if (s[i-1]>0) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
    }

    for (i=0;i<n;i++){
        if (mx < s[i]) mx = s[i];
    }

    cout << mx;
}
