#include <iostream>
#include "initialization.h"
using namespace std;

void counting_sort(int*& arr, int n, int max);
void LSD_radix_sort(int*& arr, int n);

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
    
    LSD_radix_sort(arr_B, n);
    reverse_array(arr_B, n);
    printf("Sorting with LSD Radix Sort: ");
    printout_array(arr_B, 1, n);

    delete[] arr_A;
    delete[] arr_B;
    
    return 0;
}

void counting_sort(int*& arr, int n, int max)
{
    int freq[10];
    int *out = new int[n];

    for (int pass=1; max/pass > 1; pass*=10){           
        for (int i=0; i < 10; i++)
            freq[i] = 0;
        for (int i=0; i < n; i++)    
            freq[arr[i]/pass%10]++;
        for (int i=1; i < 10; i++)
            freq[i] = freq[i] + freq[i-1];
        for (int i=n-1; i >= 0; i--){
            out[freq[arr[i]/pass%10] - 1] = arr[i]; // 'arr' should fit 'out'
            freq[arr[i]/pass%10]--;
        }
        duplicate_array(out, arr, n);
    }

    duplicate_array(out, arr, n);

    delete[] out;            
}

void LSD_radix_sort(int*& arr, int n)
{
    int max = getMax(arr, n);

    counting_sort(arr, n, max);
}