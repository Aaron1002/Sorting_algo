#include <iostream>
#include <climits>
#include <cmath>
#include "initialization.h"
using namespace std;

void merg_sort(int*& arr, int start, int end);
void merge(int*& arr, int start, int mid, int end);

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
    
    merg_sort(arr_B, 0, n-1);
    printf("Sorting with Merge Sort: ");
    printout_array(arr_B, 1, n);

    delete[] arr_A;
    delete[] arr_B;
    
    return 0;
}

void merg_sort(int*& arr, int start, int end){
    if (start < end){   // **when start==mid==end,recursion終止**
        int mid = floor( (start+end)/2 );   
        merg_sort(arr, start, mid); //前半sort
        merg_sort(arr, mid+1, end); //後半sort
        merge(arr, start, mid, end);    
    }
}
void merge(int*& arr, int start, int mid, int end){
    
    int n1 = mid - start + 1;   //前半的元素數量
    int n2 = end - mid; //後半的元素數量
    double *L = new double[n1+1]; 
    double *R = new double[n2+1]; 
    
    for (int i=0; i<n1; i++){   //放前半元素
        L[i] = arr[start+i];
    }
    for (int i=0; i<n2; i++){   //放後半元素
        R[i] = arr[mid+i+1];
    }
    
    L[n1] = INT_MAX;    
    R[n2] = INT_MAX;    
/*  設終止條件給下面i,j的移動，當一陣列空時，INT_MAX(sentinel value)
    會讓該陣列不再被選取。其中，INT_MAX為int之最大值(可視為無限大)  */

    int i = 0;
    int j = 0;
    for (int k=start; k<end+1; k++){    //比較前半&後半個元素大小並放入原array
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
    delete[] L;
    delete[] R;
    
}