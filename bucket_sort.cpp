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
    
    bucket_sort(arr_B, n);
    reverse_array(arr_B, n);
    printf("Sorting with Bucket Sort: ");
    printout_array(arr_B, 1, n);
    if (is_arr_desc(arr_B, n))
        printf("order OK!");
    else 
        printf("!!WRONGLY SORTED!!");

    delete[] arr_A;
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

void bucket_sort(int*& arr, int n)
{
    vector<float> b[10];    // bucket
    float *temp_arr = new float[n]; // float data

    int max = getMax(arr, n);
    int digit = 0;

    /* Find the max digit */
    for (int i=1; max/i > 1; i*=10)
        digit++;    

    /* Data processing */    
    for (int i=0; i<n; i++){
        temp_arr[i] = (static_cast<float>(arr[i]) / pow(10, digit));    // hashing function
        int index = temp_arr[i] * 10;   // bucket index
        b[index].push_back(temp_arr[i]);    // insert data into bucket
    }   
    delete[] temp_arr;  

    /* Sort in seperate bucket */     
    for (int i=0; i < 10; i++)    
        insertion_sort(b[i]);
    
    /* Combine sorted bucket */
    int index = 0;
    for (int i=0; i<10; i++){
        for (int j=0; j<b[i].size(); j++){
            arr[index++] = static_cast<int>(b[i][j] * pow(10, digit));
        }
    } 
}