#include <iostream>
#include "initialization.h"
using namespace std;

void insertion_sort(int*& arr, int n);

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

    clock_t start = clock();
    insertion_sort(arr_B, n);
    reverse_array(arr_B, n);
    clock_t end = clock();
    double elapsed_ms = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Sorting with Insertion Sort: ");
    printout_array(arr_B, 1, n);
    if (is_arr_desc(arr_B, n))
        printf("order OK!\n");
    else 
        printf("!!WRONGLY SORTED!!\n");

    cout << "Execution time: " << elapsed_ms << " ms" << endl;

    delete[] arr_A;
    delete[] arr_B;
    
    return 0;
}

void insertion_sort(int*& arr, int n)
{
    for (int i=1; i<n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}