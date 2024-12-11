#include <iostream>
#include "initialization.h"
using namespace std;

void insertion_sort(int*& arr, int n);
void bucket_sort(int*& arr, int n);

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
    
    //bucket_sort(arr_B, n);
    printf("Sorting with Bucket Sort: ");
    printout_array(arr_B, 1, n);

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

void bucket_sort(int*& arr, int n)
{
    int max = getMax(arr, n);
    int digit = 0;

    for (int i=1; max/i > 0; i*=10) // calaulate the max digit
        digit++;    
}