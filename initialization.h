#include <iostream>
#include <climits>
#include <cmath>
#include <ctime>
using namespace std;

bool print_or_not = 0;
int n = 0;
int a_min = 0;
int a_max = 0;
int rs = 0;

void create_array(int*& arr, int n, int min, int max)
{
    for (int i=0; i<n; i++){
        arr[i] = rand() % (max - min + 1) + min;
    }   
}

void printout_array(int*& arr, int row, int column)
{
    for (int i=0; i<column; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "---------------------------------------------" << endl;
}

void duplicate_array(int*& A, int*& B, int n){
    for (int i=0; i<n; i++){
        B[i] = A[i];
    }
}

int getMax(int*& arr, int n)
{
    int max = arr[0];

    for (int i=1; i < n-1; i++){
        if (arr[i+1] > max){
            max = arr[i+1];
        }
    }

    return max;
}

void reverse_array(int*& arr, int){
    int temp;
    for(int i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

bool is_arr_desc(int*& arr, int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] < arr[i+1]) return false;
    }
    return true;
}

