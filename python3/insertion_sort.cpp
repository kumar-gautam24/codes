// 14 9 15 12 6 8 13
 // it sets every element to its correct position
 // it makes left swap till the element is in correct postion
// time complexity O(n2)

 #include<bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int arr[],int n){

    for (int i = 0; i < n;i++){
        int j = i;
        while(j>0&&arr[j]<arr[j-1]){
            swap(arr, j, j - 1);
            j--;
        }
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n;i++){
        cout << arr[i]<<" ";
    }
}