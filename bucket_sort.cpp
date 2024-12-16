/*
   This code can be compiled and run ok.
	   
   compile:
     g++ bucket_sort.cpp -o bucket
   
   pseudocode:
   
   void insertion_sort(vector<float>& bucket)
        for (int i=1; i<bucket.size(); i++){
            float key = bucket[i];
            int j = i - 1;

            while (j>=0 && bucket[j] > key){
                bucket[j+1] = bucket[j];
                j--;
            }
            bucket[j+1] = key;
        }


    void bucket_sort(int*& arr, int n) 
        // Step 1: Find the maximum value in the array
        int max_val = getMax(arr, n);

        // Step 2: Create and initialize buckets
        vector<vector<float>> buckets(n);

        // Step 3: Distribute elements into buckets based on value
        for (int i = 0; i < n; i++) {
            int index = (static_cast<long long>(arr[i]) * (n - 1)) / max_val; // Handle large arrays
            buckets[index].push_back(arr[i]);
        }

        // Step 4: Sort each bucket using insertion sort in non-decreasing order
        for (auto& bucket : buckets) {
            insertion_sort(bucket);
        }

        // Step 5: Collect sorted elements from buckets in increasing order
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (float num : buckets[i]) {
                arr[idx++] = static_cast<int>(num);
            }
        }
 
   coded by 王晏國, ID: H44114025, email: h44114025@gs.ncku.edu.com
   date: 2024.12.16
*/

#include <iostream>
#include <vector>
#include "initialization.h"
using namespace std;

void insertion_sort(vector<float>& bucket);
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
    delete[] arr_A;

    clock_t start = clock();
    bucket_sort(arr_B, n);
    reverse_array(arr_B, n);
    clock_t end = clock();
    double elapsed_ms = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Sorting with Bucket Sort: ");
    printout_array(arr_B, 1, n);
    if (is_arr_desc(arr_B, n))
        printf("order OK!\n");
    else 
        printf("!!WRONGLY SORTED!!\n");

    /* Sorting execution time */    
    cout << "Execution time: " << elapsed_ms << " ms" << endl;
    
    delete[] arr_B;
    
    return 0;
}

void insertion_sort(vector<float>& bucket)
{
    for (int i=1; i<bucket.size(); i++){
        float key = bucket[i];
        int j = i - 1;

        while (j>=0 && bucket[j] > key){
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}

void bucket_sort(int*& arr, int n) {
    // Step 1: Find the maximum value in the array
    int max_val = getMax(arr, n);

    // Step 2: Create and initialize buckets
    vector<vector<float>> buckets(n);

    // Step 3: Distribute elements into buckets based on value
    for (int i = 0; i < n; i++) {
        int index = (static_cast<long long>(arr[i]) * (n - 1)) / max_val; // Handle large arrays
        buckets[index].push_back(arr[i]);
    }

    // Step 4: Sort each bucket using insertion sort in non-decreasing order
    for (auto& bucket : buckets) {
        insertion_sort(bucket);
    }

    // Step 5: Collect sorted elements from buckets in increasing order
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[idx++] = static_cast<int>(num);
        }
    }
}

