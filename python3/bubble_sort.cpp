//bubble sort , adjacent elements are compared and swapped if they are smaller than the previous element, 
// loops from 0 to n-1, then 0 to n-2, then 0 to n-3 and so on, finally 0 to 1
// time complexity O(n2) best O(n)
//space complexity 0(1)
// use didSwap for optimization 

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int arr[], int n){
    for (int i = n - 1; i > 0;i--){
        // can be optimized using a flag to check if any swap is done in the inner loop
        for (int j = 0; j < i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j + 1);
            }
        }
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    bubble_sort(arr, n);
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}