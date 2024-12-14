#include <iostream>
#include "initialization.h"
using namespace std;

void deleteMax(int*&, int&);
void heapify(int*&, int, int);
void heapSort(int*&, int, int);

int main ()
{
    cout << "print_or_not(0/1), n, min, max, rs:" << endl;
    cin >> print_or_not >> n >> a_min >> a_max >> rs;

    int* arr_A = new int[n];
    int* arr_B = new int[n];
    srand(rs);
    
    create_array(arr_A, n, a_min, a_max);
    duplicate_array(arr_A, arr_B, n);
    
    if (print_or_not){
        printf("The random numbers are: ");
        printout_array(arr_A, 1, n);
    }
    
    heapSort(arr_B, 1, n);
    reverse_array(arr_B, n);
    printf("Sorting with Heap Sort: ");
    printout_array(arr_B, 1, n);
    if (is_arr_desc(arr_B, n))
        printf("order OK!");
    else 
        printf("!!WRONGLY SORTED!!");

    delete[] arr_A;
    delete[] arr_B;
    
    return 0;
}

void deleteMax(int*& old_A, int& remain_size){
    swap(old_A[0], old_A[remain_size-1]); // swap the last and the first element
    remain_size--;
    heapify(old_A, 0, remain_size);    // adjust the heap
}

void heapify(int*& old_A, int from, int remain_size){
    int parent = from; // index
    int L_child = 2 * parent + 1;
    int R_child = 2 * parent + 2;
    int largest = parent;
    
    if (L_child < remain_size && old_A[L_child] > old_A[parent]){
        largest = L_child;
    }
    if (R_child < remain_size && old_A[R_child] > old_A[largest]){
        largest = R_child;
    }
    
    if (largest != parent){
        swap(old_A[largest], old_A[parent]);
        heapify(old_A, largest, remain_size);
    }
    
}

void heapSort(int*& old_A, int row, int n){
    int remain_size = n;
    
    // Build a heap
    for (int i=n/2; i>=0; i--){
        heapify(old_A, i, n);  
    }
    
    for (int i=0; i<n; i++){
        deleteMax(old_A, remain_size);
    }

}