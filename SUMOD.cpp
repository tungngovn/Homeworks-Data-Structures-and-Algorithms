#include <iostream>
#include <math.h>

using namespace std;

int m = pow(10,9) + 7;
int n;
int s = 0;
int a[100000];

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++){
        s = (s+a[i])%m;
    }
    cout << s;
}
