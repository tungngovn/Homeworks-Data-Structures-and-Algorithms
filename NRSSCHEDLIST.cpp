#include <iostream>

using namespace std;

int a[200];
int n, k1, k2;

bool check(int i, int j, int k);
void Solution();
void TRY(int i, int k);

int main(){
   cin >> n;
   cin >> k1;
   cin >> k2;
   TRY(0,0);
}

bool check(int i, int j, int k){
    if(i>0){
        if(!(k||j)) return false;
        if((k<k1)&&(!j)) return false;
        if((k>=k2)&&j) return false;
    }
    return true;
}

void Solution(){
    for (int i=0; i<n;i++) cout << a[i];
    cout << endl;
}

void TRY(int i, int k){
    for(int j=0;j<=1;j++){
        if (check(i,j,k)){
            a[i] = j;
            if (i == n-1){
                if(j) k++;
                if(k>=k1) Solution();
            }
            else{
                if(j) TRY(i+1,k+1);
                else TRY(i+1,0);
            }
        }
    }
}
