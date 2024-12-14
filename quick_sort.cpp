#include <iostream>
#include "initialization.h"
using namespace std;

void quickSort(int*&, int, int);
int partition(int*&, int, int);

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
    
    quickSort(arr_B, 0, n-1);
    reverse_array(arr_B, n);
    printf("Sorting with Insertion Sort: ");
    printout_array(arr_B, 1, n);
    if (is_arr_desc(arr_B, n))
        printf("order OK!");
    else 
        printf("!!WRONGLY SORTED!!");

    delete[] arr_A;
    delete[] arr_B;

    return 0;
}

void quickSort(int*& old_B, int low, int high){
    if (low < high){
        int mid = partition(old_B, low, high);
        quickSort(old_B, low, mid-1);
        quickSort(old_B, mid+1, high);
    }    
}

int partition(int*& old_B, int low, int high){
    int pivot = old_B[high];
    int i = low - 1;

    for (int j=low; j<=(high-1); j++){
        if (old_B[j] <= pivot){
            i++;
            swap(old_B[i], old_B[j]);
        }
    }
    swap(old_B[i+1], old_B[high]);
    return (i+1);
}