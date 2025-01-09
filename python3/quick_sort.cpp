// works on divide and conquer , puts the pivot to correct then sorts the remaining unsorted

#include<bits/stdc++.h>

using namespace std;

int partition(int arr[],int low,int high){

    int pivot = arr[low];
    int i = low, j = high;

   while(i<j){

        do{
            i++;
        } while (arr[i] <= pivot);
        do{
            j--;
        } while (arr[j] > pivot);
        if(i<j)
            swap(arr[i], arr[j]);
   }
   swap(arr[low], arr[j]);
   return j;
}

void quickSort(int arr[],int low,int high){

    if(low<high){
        int part = partition(arr, low, high);
        quickSort(arr, low, part);
        quickSort(arr, part + 1, high);
    }
}

int main(){
    int arr[] = {5, 2, 3, 1, 4};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}