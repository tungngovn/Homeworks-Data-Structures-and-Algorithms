#include <iostream>

using namespace std;

void insertionSort(int A[], int N); // Sap xep chen
void selectionSort(int a[], int n);
void bubleSort(int a[], int n);
void mergeSort(int a[], int L, int R);
void merge(int a[], int L, int m, int R);
void quickSort(int a[], int L, int R);
int partition(int a[], int L, int R, int indexPivot);
void swap(int* a, int* b);
void heapify(int a[], int i, int n);
void buildHeap(int a[], int n);
void heapSort(int a[], int n);

int main()
{
    int n = 10;
    int a[n];
    for (int i=0; i<n;i++) a[i]= 10-i;
    for (int i=0; i<n;i++) cout << a[i];
    //insertionSort(a,n);
    //selectionSort(a,n);
    //bubleSort(a,n);
    //mergeSort(a,0,n);
    //quickSort(a,0,9);
    heapSort(a, 10);
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
        int index = (L+R)/2;
        index = partition(a,L,R,index);
        if(L<index) quickSort(a, L, index-1);
        if(index<R) quickSort(a, index+1, R);
    }
}

int partition(int a[], int L, int R, int indexPivot){
    int pivot = a[indexPivot];
    swap(a[indexPivot], a[R]);
    int storeIndex = L;
    for(int i = L; i<=R-1; i++){
        if(a[i]<pivot){
            swap(a[storeIndex], a[i]);
            storeIndex++;
        }
    }
    swap(a[storeIndex], a[R]);
    return storeIndex;
}

void swap(int *a, int *b){
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

void heapify(int a[], int i, int n){
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if(L <= n && a[L] > a[i]) max = L;
    if(R <= n && a[R] > a[max]) max = R;
    if(max != i){
        swap(a[i], a[max]);
        heapify(a, max, n);
    }
}

void buildHeap(int a[], int n){
    for(int i = n/2; i>=0; i--) heapify(a, i, n);
}

void heapSort(int a[], int n){
    buildHeap(a, n);
    for(int i = n; i>0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i-1);
    }
}
