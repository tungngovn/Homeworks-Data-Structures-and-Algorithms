#include <iostream>

using namespace std;

void insertionSort(int A[], int N);
void selectionSort(int a[], int n);
void bubleSort(int a[], int n);
void mergeSort(int a[], int L, int R);
void merge(int a[], int L, int m, int R);
void quickSort(int a[], int L, int R);

int main()
{
    int n = 10;
    int a[n];
    for (int i=0; i<n;i++) a[i]= 10-i;
    for (int i=0; i<n;i++) cout << a[i];
    //insertionSort(a,n);
    //selectionSort(a,n);
    //bubleSort(a,n);
    mergeSort(a,0,n);
    for (int i=0;i<n;i++) cout << endl << a[i];
}

void insertionSort(int A[], int N){
    for (int k=1; k<N; k++){
        int last = A[k];
        int j = k;
        while(j>=1 && A[j-1]>last){
            A[j] = A[j-1];
            j--;
        }
        A[j]=last;
    }
}

void selectionSort(int a[], int n){
    for (int k = 0; k<n;k++){
        int min=k;
        for (int j=k+1;j<n;j++){
            if(a[min]>a[j]) min =j;
        }
        int tmp = a[min];
        a[min] = a[k];
        a[k] = tmp;
    }

}

void bubleSort(int a[], int n){
    int swapped;
    do{
        swapped = 0;
        for (int i = 0; i<n-1; i++){
            if (a[i]>a[i+1]){
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = 1;
            }
        }
    }while(swapped == 1);
}

void mergeSort(int a[], int L, int R){
    if(L<R){
        int m = (L+R)/2;
        mergeSort(a,L,m);
        mergeSort(a,m+1,R);
        merge(a,L,m,R);
    }
}

void merge(int a[], int L, int m, int R){
    int i = L;
    int j = m+1;
    int TA[R];
    for (int k = L; k<=R; k++){
        if(i>m){
            TA[k] = a[j];
            j++;
        }
        else if(j>R) {
            TA[k] = a[i];
            i++;
        }
        else{
            if(a[i]<a[j]){
                TA[k] = a[i];
                i++;
            }
            else{
                TA[k] = a[j];
                j++;
            }
        }
    }
    for (int k = L; k<=R; k++) a[k] = TA[k];
}

void quickSort(int a[], int L, int R){
    if(L<R){
        int index = partition(a,L,R,index);
        if(L<index)

    }
}
