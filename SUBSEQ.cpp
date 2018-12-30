#include <iostream>

using namespace std;

#define MAX 1000000

int n,m;
int a[MAX];

int s[MAX];

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    int c=0;
    for (int i=0;i<n;i++){
        if (a[i]<=m) c++;
        // cout << c << endl;
        s[i]=a[i];
        for (int j=i+1;j<n;j++){
            if((s[j-1] + a[j])<=m){
                //cout <<s[j] << endl;
                c++;
                s[j]=s[j-1]+a[j];

            }
            else break;
        }
    }

    cout << c;
}
